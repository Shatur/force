#include "sqldataprovider.h"

#include "common.h"
#include "datatypes.h"
#include "jsondata.h"

#include <QDebug>
#include <QFile>
#include <QDir>
#include <QByteArray>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonArray>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QStringList>

const int DB_VERSION = 2;
_str_const SET1 = "requests1";
_str_const SET2 = "requests2";

using namespace Fesko;

SQLDataProvider* Fesko::sql_provider()
{
    static SQLDataProvider instance;
    return &instance;
}

SQLDataProvider::SQLDataProvider(QObject *parent) : QObject(parent)
{
    
}

/*void SQLDataProvider::cacheGetData(QString method, QUrlQuery params, const QJsonObject &resp)
{

}*/

int SQLDataProvider::lastLoginDate(QDate& out)
{
    int err = prepare_db();
    if (NO_ERROR != err)
    {
        qDebug()<<"prepare_DB login error!";
        return err;
    }
    out = dbData.lastLogin;

    return NO_ERROR;
}

int SQLDataProvider::lastSyncDate(QDate &out)
{
    int err = prepare_db();
    if (NO_ERROR != err)
    {
        qDebug()<<"prepare_DB login error!";
        return err;
    }
    out = dbData.lastSync;

    return NO_ERROR;
}

QString SQLDataProvider::lastLogin()
{
    prepare_db();
    return dbData.login;
}

QString SQLDataProvider::lastPass()
{
    prepare_db();
    return dbData.password;
}

int SQLDataProvider::fontSize()
{
    prepare_db();
    return dbData.font_size;
}

void SQLDataProvider::beginSyncSession()
{
    QString curr_set = dbData.currentSet;
    curr_set = (curr_set == SET1)?SET2:SET1;

    QSqlQuery q(QString("DELETE from ") + curr_set);
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
    }

    dbData.currentSet = curr_set;
}

void SQLDataProvider::commitSyncSession()
{
    QSqlQuery q;
    q.prepare("UPDATE general SET current_set = :curr_set, last_sync = :lastSync");
    q.bindValue(":curr_set", dbData.currentSet);
    q.bindValue(":lastSync", QDate::currentDate());
    dbData.lastSync = QDate::currentDate();
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
    }

}

void SQLDataProvider::rollbackSyncSession()
{
    dbData.currentSet = (dbData.currentSet == SET1)?SET2:SET1;
}

bool SQLDataProvider::mergeReport(SReport &report)
{

    QUrlQuery uq;
    uq.addQueryItem("id", QString::number(report.id));
    int cnt = outCount("setReport", uq);
    if (!cnt) return false;

    QSqlQuery q(db);

    QString s = "select params from responces where method = :method and key_params = :key ;";
    q.prepare(s);
    q.bindValue(":method", "setReport");
    q.bindValue(":key", uq.toString());

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }

    int resp_id = q.record().indexOf("params");
    q.first();

    QString str = q.value(resp_id).toString();

    QUrlQuery uc2(str.toUtf8());
    QString vals = uc2.queryItemValue("data", QUrl::PrettyDecoded);


    qDebug()<<"VALS TO MERGE for "<<report.id;
    qDebug()<<vals;    

    QJsonDocument jsonResponse = QJsonDocument::fromJson(vals.toUtf8());
    QJsonArray arr = jsonResponse.array();

    mergeJSON(arr, report);

//    if (NO_ERROR == fromJSON())

    return true;
}

bool SQLDataProvider::mergeComments(int report_id, TReportComments &comments)
{
    QUrlQuery uq;
    int cnt = outCount("addComment", uq);
    if (!cnt) return false;

    QSqlQuery q(db);

    QString s = "select params, key_params from responces where method = :method ;";
    q.prepare(s);
    q.bindValue(":method", "addComment");

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return false;
    }

    int params_id = q.record().indexOf("params");
    if (params_id<0)
        return false;
    int key_params_id = q.record().indexOf("key_params");
    if (key_params_id<0)
        return false;

    bool ret = false;

    while (q.next())
    {
        //parse url encoded params
        QString params =  q.value(params_id).toString();
        QUrlQuery uc2(params.toUtf8());
        SComment comment;
        QString str_date;
        QString str_time;
        QString str;

        comment.text = uc2.queryItemValue("text", QUrl::PrettyDecoded);
        str_date = uc2.queryItemValue("date", QUrl::PrettyDecoded);
        str_time = uc2.queryItemValue("time", QUrl::PrettyDecoded);
        str = str_time + " " + str_date;
        comment.time = QDateTime::fromString(str, "hh:mm dd.MM.yyyy");

        //get report id
        QString key = q.value(key_params_id).toString();
        QUrlQuery uc3(key.toUtf8());
        int id = uc3.queryItemValue("report_id", QUrl::PrettyDecoded).toInt();
        if (id == report_id)
        {
            comment.reportID = report_id;
            comments.push_back(comment);
            ret = true;
        }
    }// for all records

    return ret;
}

int SQLDataProvider::outCount(QString method, QString key)
{
    QSqlQuery q(db);

    QString s = "select count (*) as cnt from responces where method = :method";
    if (key.length())
    {
        s = s + " and key_params = :key ";
    }
    s = s+ ";";

    q.prepare( s );
    q.bindValue(":method", method);
    if (key.length())
    {
        q.bindValue(":key", key);
    }
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }

    q.first();
    int cnt = q.value(0).toInt();
    return cnt;
}

int SQLDataProvider::outCount(QString method, QUrlQuery key)
{
    return outCount(method, key.toString());
}

void SQLDataProvider::clearResponces()
{
    QSqlQuery q;
    q.prepare("delete from responces;");
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return;
    }
}

int SQLDataProvider::rawData(QVector<SStoredRawData> &out)
{
    int err = prepare_db();
    if (NO_ERROR != err)
    {
        return err;
    }

    QSqlQuery q;
    q.prepare("select * from responces;");
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }

    int id_id = q.record().indexOf("id");
    if (id_id<0) return ERR_DB_ERROR;
    int key_id = q.record().indexOf("key_params");
    if (key_id<0) return ERR_DB_ERROR;
    int method_id = q.record().indexOf("method");
    if (method_id<0) return ERR_DB_ERROR;
    int data_id = q.record().indexOf("params");
    if (data_id<0) return ERR_DB_ERROR;
    int raw_name_id = q.record().indexOf("data_name");
    if (raw_name_id<0) return ERR_DB_ERROR;
    int raw_type_id = q.record().indexOf("data_type");
    if (raw_type_id<0) return ERR_DB_ERROR;
    int raw_file_id = q.record().indexOf("data_file");
    if (raw_file_id<0) return ERR_DB_ERROR;
    int raw_bin_id = q.record().indexOf("data_raw");
    if (raw_bin_id<0) return ERR_DB_ERROR;

    out.clear();

    while (q.next())
    {
        SStoredRawData item;
        item.id = q.value(id_id).toInt();
        item.method = q.value(method_id).toString();
        item.key = q.value(key_id).toString();
        item.data = q.value(data_id).toString();

        item.binary.name = q.value(raw_name_id).toString();
        item.binary.file = q.value(raw_file_id).toString();
        item.binary.type = q.value(raw_type_id).toString();
        item.binary.data = q.value(raw_bin_id).toByteArray();

        out.push_back(item);
    }

    return NO_ERROR;
}

int SQLDataProvider::removeRawEntry(int id)
{
    QSqlQuery q;
    q.prepare("delete from responces where id = :id ;");
    q.bindValue(":id", id);

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }

    return NO_ERROR;
}

int SQLDataProvider::doLogin(QString login, QString password)
{
    qDebug()<<500;
    int err = prepare_db();
    if (NO_ERROR != err)
    {
        qDebug()<<"prepare_DB login error!";
        return err;
    }
    if ((!dbData.login.length()) || (!dbData.password.length()))
        return ERR_BAD_LOGIN;
    if ((login != dbData.login) || (password != dbData.password))
        return ERR_BAD_LOGIN;
    return NO_ERROR;
}

int SQLDataProvider::doGetData(QString method, QUrlQuery params, QString &resp)
{
    QString wset = dbData.currentSet;
    QSqlQuery q;
    /*QString csql = QString("SELECT count(*) as cnt from ")+wset+" where method=:method";
    if (params.toString().length())
        csql+=" and params=:params";
    q.prepare(csql);
    q.bindValue(":method", method);
    if (params.toString().length())
        q.bindValue(":params", params.toString());
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }
    q.first();
    int cnt_id = q.record().indexOf("cnt");
    qDebug()<<"CNT_ID: "<<cnt_id;
    qDebug()<<"CNT_VAL "<<q.value(0);
    int cnt = q.value(0).toInt();
    qDebug()<<"COUNTER: "<<cnt;
*/
    QString ssql = QString("SELECT response from ")+wset+" where method=:method";
    if (params.toString().length())
        ssql+=" and params=:params";

    q.prepare(ssql);
    q.bindValue(":method", method);

    if (params.toString().length())
        q.bindValue(":params", params.toString());

    qDebug()<<params.toString();
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }

    int resp_id = q.record().indexOf("response");
    if (resp_id <0 )
        return ERR_DB_ERROR;

    /*q.last();
    int cnt = q.at()-1;
    qDebug()<<cnt;
    if (!cnt)
        return ERR_SRV_NO_DATA;*/
    /*bool hasRecs = q.next();
    q.last();
    int cnt2 = q.at() + 1;
    bool hasFirst = q.first();

    qDebug()<<"NEXT: "<<hasRecs;
    qDebug()<<"FIRST: "<<hasFirst;
    qDebug()<<"CNT: "<<cnt;

    if (!hasFirst)
        return ERR_SRV_NO_DATA;*/
    q.first();

    if (!q.value(resp_id).isValid())
        return ERR_SRV_NO_DATA;

    resp = q.value(resp_id).toString();

    return NO_ERROR;
}

int SQLDataProvider::doSetData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData *data, QString &resp)
{
    qDebug()<<100001<<params.toString();
    bool isUpdate = !key.isEmpty();
    if (isUpdate)
        isUpdate = isUpdate && outCount(method, key);
    qDebug()<<"IS_UPDATE: "<<isUpdate;

    /*if (!key.isEmpty())
    {
        int cnt = outCount(method, key);
        if (cnt)
        {
            QSqlQuery q;
            q.prepare("delete from responces where method = :method and key_params = :key_params;");
            q.bindValue(":method", method);
            q.bindValue(":key_params", key.toString());
            if (!q.exec())
            {
                qDebug()<<q.lastError().text();
                return ERR_DB_ERROR;
            }
        }
    }*/

    QSqlQuery q;
    QString sql;

    if (data && (!data->isEmpty()))
    {
        sql = (isUpdate)? "UPDATE responces SET method = :method ,key_params = :key_params,params = :params ,data_name = :data_name ,data_file = :data_file,data_type = :data_type,data_raw = :data_raw WHERE method = :method AND key_params = :key_params;"
                         :"INSERT INTO responces (method,key_params,params,data_name,data_file,data_type,data_raw) VALUES ( :method, :key_params, :params, :data_name, :data_file, :data_type, :data_raw);";
        qDebug()<<"SQL: "<<sql;
        q.prepare(sql);
        q.bindValue(":method", method);
        q.bindValue(":key_params", key.toString());
        QString str_params = params.toString();
        q.bindValue(":params",  str_params);
        q.bindValue(":data_name", data->name);
        q.bindValue(":data_file", data->file);
        q.bindValue(":data_type", data->type);
        q.bindValue(":data_raw", data->data);
    }
    else
    {
        sql = (isUpdate)? "UPDATE responces SET method = :method ,key_params = :key_params,params = :params where method = :method AND key_params = :key_params"
                         :"INSERT INTO responces (method,key_params,params) VALUES ( :method, :key_params, :params);";
        qDebug()<<"SQL: "<<sql;
        q.prepare(sql);
        q.bindValue(":method", method);
        q.bindValue(":key_params", key.toString());
        QString str_params = params.toString();
        q.bindValue(":params",  str_params);

    }

    /*if (!data)
    {
        q.prepare(QString("INSERT INTO responces (method,key_params,params,response) VALUES ( :method, :key_params, :params, :response);"));
    //q.bindValue(":working_set", dbData.currentSet);
        q.bindValue(":method", method);
        q.bindValue(":key_params", key.toString());
        QString str_params = params.toString();
        q.bindValue(":params",  str_params);
    }
    else
    {
        q.prepare(QString("INSERT INTO responces (method,key_params,params,response,data_name,data_file,data_type,data_raw) VALUES ( :method, :key_params, :params, :response, :data_name, :data_file, :data_type, :data_raw);"));
        q.bindValue(":method", method);
        q.bindValue(":key_params", key.toString());
        QString str_params = params.toString();
        q.bindValue(":params",  str_params);
        q.bindValue(":data_name", data->name);
        q.bindValue(":data_file", data->file);
        q.bindValue(":data_type", data->type);
        q.bindValue(":data_raw", data->data);
    }*/

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return ERR_DB_ERROR;
    }
    return NO_ERROR;
}

int SQLDataProvider::createDB()
{
    qDebug()<<"==== Creating db at "<<dbFileName();
    if (QFile::exists(dbFileName()))
    {
        QFile::remove(dbFileName());
    }
    qDebug()<<100;
    //Get create DB sql from DB
    QFile file(":/backend/createdb.sql");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Error with resource!";
        return ERR_INTERNAL_ERROR;
    }
    QStringList init_sql = QString(file.readAll()).split("\n");

    qDebug()<<200;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFileName());

    if (!db.open())
    {
        qDebug()<<"Cant open DB!";
        return ERR_DB_ERROR;
    }

    QSqlQuery q;
    for(int i=0; i< init_sql.size(); i++)
    {
        if (!init_sql[i].length()) continue;
        if (!q.exec(init_sql[i]))
        {
            qDebug()<<q.lastError().text();
            db.close();
            return ERR_DB_ERROR;
        }
    }

    qDebug()<<300;
    q.prepare("INSERT INTO general (current_set, version, font_size) VALUES (:current_set, :version, :font_size)");
    q.bindValue(":current_set", "requests1");
    q.bindValue(":version", DB_VERSION);
    q.bindValue(":font_size", 14);

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        db.close();
        return ERR_DB_ERROR;
    }

    db.close();

    return NO_ERROR;
}

QString SQLDataProvider::dbFileName()
{
     QString path = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
     QDir dir(path);
     if (!dir.exists(path))
     {
         dir.mkpath(path);
     }
     return path + "/foffline.db";
}

void SQLDataProvider::cacheLogin(QString login, QString password)
{
    int err = prepare_db();

    if (NO_ERROR != err)
    {
        return;
    }

    QSqlQuery q;
    q.prepare("UPDATE general SET login = :login, password = :password, last_login = :last_login;");
    q.bindValue(":login", login);
    q.bindValue(":password", password);
    q.bindValue(":last_login", QDate::currentDate());

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return;
    }

    dbData.login = login;
    dbData.password = password;
    dbData.lastLogin = QDate::currentDate();

    return;
}

void SQLDataProvider::cacheGetData(QString method, QUrlQuery params, const QJsonObject &resp)
{
    QJsonDocument doc(resp);
    QByteArray json_Str = doc.toJson();
    QSqlQuery q;
    q.prepare(QString("INSERT INTO ") + dbData.currentSet +"  (method,params,response) VALUES ( :method, :params, :response);");
    //q.bindValue(":working_set", dbData.currentSet);
    q.bindValue(":method", method);
    q.bindValue(":params", params.toString());
    q.bindValue(":response", QString(json_Str)/*.toBase64()*/);

    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        return;
    }

    return;
}

void SQLDataProvider::cacheFontSize(int fontSize)
{
    QSqlQuery q;
    q.prepare("UPDATE general SET font_size = :font_size");
    q.bindValue(":font_size", fontSize);

    if (!q.exec()) // foo()
    {
        qDebug()<<q.lastError().text();
        return;
    }

    dbData.font_size = fontSize;
}

int SQLDataProvider::init()
{
    int err = NO_ERROR;
    if (!QFile::exists(dbFileName()))
    {
        err = createDB();
        if (NO_ERROR != err)
            return err;
    }
    err = openDB();
    if (err != NO_ERROR)
    {
        qDebug()<<"Open DB error!";
        err = createDB();
        if (NO_ERROR != err)
            return err;
        return openDB();
    }

    qDebug()<<"DB init success done";
    return NO_ERROR;
}

int SQLDataProvider::openDB()
{
    qDebug()<<"OpenDB started";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFileName());

    if (!db.open())
    {
        return ERR_DB_ERROR;
    }

    QSqlQuery q("SELECT * FROM general");
    if (!q.exec())
    {
        qDebug()<<q.lastError().text();
        db.close();
        return ERR_DB_ERROR;
    }

    int ver_index = q.record().indexOf("version");
    if (ver_index <0)
    {   db.close();
        return ERR_DB_ERROR;
    }
    int currset_idx = q.record().indexOf("current_set");
    if (currset_idx <0)
    {   db.close();
        return ERR_DB_ERROR;
    }
    int login_id = q.record().indexOf("login");
    if (login_id <0)
    {   db.close();
        return ERR_DB_ERROR;
    }
    int pass_id =  q.record().indexOf("password");
    if (pass_id <0)
    {   db.close();
        return ERR_DB_ERROR;
    }
    int last_login_id =  q.record().indexOf("last_login");
    if (last_login_id <0)
    {   db.close();
        return ERR_DB_ERROR;
    }
    int last_sync_id = q.record().indexOf("last_sync");
    if (last_sync_id <0)
    {   db.close();
        return ERR_DB_ERROR;
    }
    int font_size_id = q.record().indexOf("font_size");
    if (font_size_id <0)
    {   db.close();
        return ERR_DB_ERROR;
    }

    q.first();
    dbData.ver = q.value(ver_index).toString().toInt();
    if (dbData.ver != DB_VERSION)
    {
        db.close();
        return ERR_DB_ERROR;
    }

    dbData.currentSet = q.value(currset_idx).toString();
    if (!dbData.currentSet.length())
    {
        db.close();
        return ERR_DB_ERROR;
    }

    dbData.lastLogin = q.value(last_login_id).toDate();
    dbData.login = q.value(login_id).toString();
    dbData.password = q.value(pass_id).toString();
    dbData.lastSync = q.value(last_sync_id).toDate();
    dbData.font_size = q.value(font_size_id).toInt();

    return NO_ERROR;
}
