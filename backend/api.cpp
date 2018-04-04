#include "api.h"
#include "common.h"
#include "jsondata.h"
#include "version.h"

#include <QApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QUrlQuery>
#include <QDate>

//_str_const BASE_URL="tech.fesko.com.ua";
#ifdef TEST_BASE
_str_const BASE_URL="popik.fesko.com.ua";
#else
_str_const BASE_URL="tech.fesko.com.ua";
#endif
_str_const LOGIN_SCRIPT="/proj/mobile/login.php";
_str_const ROUTE_SCRIPT="/proj/mobile/route.php";

using namespace Fesko;

QString Fesko::errorToString(int err)
{
    QString msg;
    switch(err)
    {
        case NO_ERROR:\
            msg = "Помилки відсутні";
            break;
    case ERR_BAD_LOGIN:
            msg = "Невірний логін або пароль";
            break;
    case ERR_BAD_TOKEN:
            msg = "Невірний сеанс. Необхідний вхід";
            break;
    case ERR_SRV_NO_DATA:
            msg = "Дані відсутні";
            break;
    case ERR_CONNECT:
            msg = "Немає з'єднання";
            break;
    case ERR_PROTOCOL:
            msg = "Помилка протоколу. Оновіть додаток";
            break;
    case ERR_INTERNAL_ERROR:
            msg = "Внутрішня помилка";
            break;
    case ERR_DB_ERROR:
            msg = "Помилка при роботі з локальними даними";
        break;
    default:
            msg = QString("Невідома помилка #%1").arg(QString::number(err));
            break;
    }
    return msg;
}

FreskoAPI &FreskoAPI::ref()
{
    static FreskoAPI* pMe = NULL;
    if (!pMe)
    {
        pMe = new FreskoAPI(NULL);
    }

    return (*pMe);
}

#define JSON_FIELD(object, json_field, var)\
    if (object.contains(json_field)) var = object[json_field]

#define JSON_FIELD_REQIRED(object, json_field, var)\
    if (!object.contains(json_field)) { return ERR_PROTOCOL;}\
        else var = object[json_field]\

#define JSON_ARRAY(object, array_obj, name)\
    if (!object.contains(name)){return ERR_PROTOCOL;}\
    if (!object[name].isArray()) { return ERR_PROTOCOL;}\
    QJsonArray array_obj = object[name].toArray();

FreskoAPI::FreskoAPI(QObject *parent) : QObject(parent)
{
    cache = NULL;
    provider = NULL;
}

void FreskoAPI::setDataProvider(BaseDataProvider *p)
{
    provider = p;
}

void FreskoAPI::setCache(BaseDataCache *c)
{
    cache = c;
}

int FreskoAPI::getAPICall(QString method, QUrlQuery params, QJsonObject &resp)
{
    if (!provider)
    {
        return ERR_INTERNAL_ERROR;
    }

    int err = provider->getData(method, params, resp);
    if (NO_ERROR != err)
    {
        return err;
    }
    if (cache)
    {
        if ((void*)cache != (void*)provider)
        {
            cache->cacheGetData(method, params, resp);
        }
    }
    return NO_ERROR;
}

int FreskoAPI::setAPICall(QString method, QUrlQuery key, QUrlQuery params, QJsonObject &resp, SApiBinaryData* data)
{

    if (!provider)
    {
        return ERR_INTERNAL_ERROR;
    }


    int err = provider->setData(method, key, params, data);

    return err;
}

int FreskoAPI::login(QString login, QString pass)
{
    if (!provider)
    {
        return ERR_INTERNAL_ERROR;
    }

    int err = provider->login(login, pass);
    if (NO_ERROR != err)
    {
        qDebug()<<"API::login error "<<err;
        return err;
    }

    if (cache)
    {
        if ((void*)cache != (void*)provider)
        {
            cache->cacheLogin(login, pass);
        }
    }

    return NO_ERROR;
}

int FreskoAPI::getShopReports(QDate date, int shopid, TShopReports &reports)
{
    QUrlQuery q;
    QJsonObject resp;
    reports.clear();

    q.addQueryItem("date",date.toString("yyyy-MM-dd"));
    q.addQueryItem("shopid", QString::number(shopid));

    int err = getAPICall("getShopReports", q, resp);

    if (NO_ERROR != err)
    {
        return err;
    }

    JSON_ARRAY(resp, sr_array, "reports");

    for(int i=0; i<sr_array.size(); i++)
    {
        QJsonObject el = sr_array[i].toObject();
        SShopReportEntry entry;
        JSON_FIELD_REQIRED(el, "id", entry.id).toString().toInt();
        JSON_FIELD(el, "client", entry.client).toString();
        JSON_FIELD(el, "status", entry.status).toString().toInt();

        reports.push_back(entry);
    }

    return NO_ERROR;
}

int FreskoAPI::getReport2(int id, SReport &out)
{
    QUrlQuery q;
    QJsonObject resp;

    q.addQueryItem("id", QString::number(id));
    int err = getAPICall("getReport2", q, resp);

    if (NO_ERROR != err)
    {
        return err;
    }    

    QJsonObject report;
    QString tmp;

    if (!resp.contains("report"))
        return ERR_PROTOCOL;
    //report = resp["report"].toObject();

    return fromJSON(resp, out);
    /*
    JSON_FIELD_REQIRED(report, "id", out.id).toString().toInt();
    JSON_FIELD_REQIRED(report, "date", tmp).toString();
    out.date = QDate::fromString(tmp, "yyyy-MM-dd");
    JSON_FIELD(report, "client", out.client).toString();
    JSON_FIELD(report, "clienttn", out.clienttn).toString();
    JSON_FIELD(report, "clientid", out.clientid).toString().toInt();
    JSON_FIELD(report, "shop", out.shop).toString();
    JSON_FIELD(report, "city", out.city).toString();
    JSON_FIELD(report, "cityid", out.cityid).toString().toInt();
    JSON_FIELD(report, "address", out.address).toString();
    JSON_FIELD(report, "shopid", out.shopid).toString().toInt();
    JSON_FIELD(report, "sp_width", out.longtitude).toString().toDouble();
    JSON_FIELD(report, "sp_height", out.latitude).toString().toDouble();
    JSON_FIELD(report, "mr", out.mr).toString();
    JSON_FIELD(report, "sv", out.sv).toString();
    JSON_FIELD(report, "status", out.status).toString().toInt();

    JSON_ARRAY(resp, catalogs, "catalogs");
    out.catalogs.clear();
    for(int i=0; i<catalogs.size(); i++)
    {
        QJsonObject jcatalog = catalogs[i].toObject();
        SCatalog catalog;
        JSON_FIELD_REQIRED(jcatalog, "id", catalog.id).toString().toInt();
        JSON_FIELD(jcatalog, "catalogName", catalog.catalogName).toString();
        JSON_FIELD(jcatalog, "catalogRule", catalog.catalogRule).toString();

        JSON_ARRAY(jcatalog, rf, "reportFields");
        for(int j=0; j<rf.size(); j++)
        {
            QJsonObject jfield = rf[j].toObject();;
            QString name, type;
            JSON_FIELD_REQIRED(jfield, "name", name).toString();
            JSON_FIELD_REQIRED(jfield, "type", type).toString();
            if (type.trimmed().toLower() == "report")
            {
                catalog.reportFields.push_back(name);
            }
            else
            {
                catalog.staticReportFields.push_back(name);
            }
        }//all reportFields array

        JSON_ARRAY(jcatalog, reportItems, "reportItems");

        for(int j=0; j<reportItems.size(); j++)
        {
            QJsonArray ri = reportItems[j].toArray();
            if (ri.size()<1) return ERR_PROTOCOL;
            SReportItem item;
            item.id = ri[0].toString().toInt();
            for (int k=1; k<ri.size(); k++)
            {
                if (!ri[k].isArray()) return ERR_PROTOCOL;
                QJsonArray val = ri[k].toArray();
                if (val.size()<2) return ERR_PROTOCOL;
                QString value = val[0].toString();
                QString type = val[1].toString();
                if (type.trimmed().toLower() == "report")
                {
                    SReportItemValue val_item;
                    int itype = 0;
                    val_item.value = value;
                    if (val.size()>2) itype = val[2].toString().toInt();
                    val_item.type = itype;
                    item.reportValues.push_back(val_item);
                }
                else
                {
                    item.staticValues.push_back(value);
                }
            }
            catalog.reportItems.push_back(item);

        }

        out.catalogs.push_back(catalog);
    }//for all catalogs

    return NO_ERROR;*/
}

int FreskoAPI::getEvents(Fesko::TEvents &out, EEventType et)
{
    QUrlQuery q;
    q.addQueryItem("etype", QString::number((int)et));
    QJsonObject resp;
    out.clear();

    int err = getAPICall("getEvents", q, resp);

    if (NO_ERROR != err)
    {
        if (err == 9)
        {
            return Fesko::NO_ERROR;
        }
        return err;
    }

    if (!resp.contains("events"))
    {
        return ERR_PROTOCOL;
    }
    if (!resp["events"].isArray())
    {
        return ERR_PROTOCOL;
    }

    JSON_ARRAY(resp, ev_array, "events");

    for(int i=0; i<ev_array.size(); i++)
    {
        QJsonObject el = ev_array[i].toObject();
        SEvent entry;
        QString tmp;
        JSON_FIELD_REQIRED(el, "id", entry.id).toInt();
        JSON_FIELD_REQIRED(el, "client", entry.client).toString();
        JSON_FIELD_REQIRED(el, "name", entry.name).toString();
        JSON_FIELD_REQIRED(el, "descr", entry.descr).toString();

        JSON_FIELD_REQIRED(el, "from_date", tmp).toString();
        entry.from_date = QDate::fromString(tmp, "yyyy-MM-dd");
        JSON_FIELD_REQIRED(el, "to_date", tmp).toString();
        entry.to_date = QDate::fromString(tmp, "yyyy-MM-dd");

        out.push_back(entry);
    }

    return NO_ERROR;
}

int FreskoAPI::getReclamList(SReclamations& out)
{
    QUrlQuery q;
    QJsonObject resp;
    out.curr.clear();
    out.fixed.clear();

    int err = getAPICall("getReclamList", q, resp);

    if ((err == ERR_NO_RECLAMATIONS) || (err == ERR_SRV_NO_DATA))
    {
        return NO_ERROR;
    }

    if (err)
    {
        return err;
    }

    if (!resp.contains("reclam"))
    {
        return ERR_PROTOCOL;
    }

    QJsonObject reclam = resp["reclam"].toObject();

    JSON_ARRAY(reclam, curr, "curr");
    for(int i=0; i<curr.size(); i++)
    {
        SReclamation entry;
        QString tmp;
        QJsonObject el = curr[i].toObject();
        JSON_FIELD_REQIRED(el, "report", entry.report).toString().toInt();
        JSON_FIELD_REQIRED(el, "date", tmp).toString();
        entry.date = QDate::fromString(tmp, "yyyy-MM-dd");
        JSON_FIELD_REQIRED(el, "shop", entry.shop).toString();
        JSON_FIELD_REQIRED(el, "adress", entry.adress).toString();
        JSON_FIELD_REQIRED(el, "city", entry.city).toString();
        JSON_FIELD_REQIRED(el, "name", entry.name).toString();
        JSON_FIELD_REQIRED(el, "info", entry.info).toString();

        out.curr.push_back(entry);
    }

    JSON_ARRAY(reclam, fixed, "fixed");
    for(int i=0; i<fixed.size(); i++)
    {
        SReclamation entry;
        QString tmp;
        QJsonObject el = fixed[i].toObject();
        JSON_FIELD_REQIRED(el, "report", entry.report).toInt();
        JSON_FIELD_REQIRED(el, "date", tmp).toString();
        entry.date = QDate::fromString(tmp, "yyyy-MM-dd");
        JSON_FIELD_REQIRED(el, "shop", entry.shop).toString();
        JSON_FIELD_REQIRED(el, "adress", entry.adress).toString();
        JSON_FIELD_REQIRED(el, "city", entry.city).toString();
        JSON_FIELD_REQIRED(el, "name", entry.name).toString();
        JSON_FIELD_REQIRED(el, "info", entry.info).toString();

        out.fixed.push_back(entry);
    }

    JSON_ARRAY(reclam, final, "final");
    for(int i=0; i<final.size(); i++)
    {
        SReclamation entry;
        QString tmp;
        QJsonObject el = final[i].toObject();
        JSON_FIELD_REQIRED(el, "report", entry.report).toInt();
        JSON_FIELD_REQIRED(el, "date", tmp).toString();
        entry.date = QDate::fromString(tmp, "yyyy-MM-dd");
        JSON_FIELD_REQIRED(el, "shop", entry.shop).toString();
        JSON_FIELD_REQIRED(el, "adress", entry.adress).toString();
        JSON_FIELD_REQIRED(el, "city", entry.city).toString();
        JSON_FIELD_REQIRED(el, "name", entry.name).toString();
        JSON_FIELD_REQIRED(el, "info", entry.info).toString();

        out.final.push_back(entry);
    }


    return NO_ERROR;

}

int FreskoAPI::setReport(SReport &report)
{
    QUrlQuery key;
    QUrlQuery data;
    key.addQueryItem("id", QString::number(report.id));
    QJsonArray root;
    for( int c=0; c<report.catalogs.size();c++)
    {
        QJsonObject catalog;
        catalog["id"] = report.catalogs[c].id;
        SCatalog& cat = report.catalogs[c];
        QJsonArray items;
        for(int i=0; i<cat.reportItems.size(); i++)
        {
            QJsonArray item;
            item.append(QString::number(cat.reportItems[i].id));
            QVector<SReportItemValue>& vals = cat.reportItems[i].reportValues;
            for(int v=0;v<vals.size(); v++)
            {
                //fallback for types
                /*switch(vals[v].type)
                {
                    case 7:
                        item.append((vals[v].value.length())?vals[v].value:QString("no"));
                        break;
                    case 2:

                    default:
                        item.append(vals[v].value);
                        break;
                }*/
                item.append(reportValueToJson(vals[v].value, vals[v].type));
            }
            items.append(item);
        }//for report items
        catalog["items"] = items;
        root.append(catalog);
    }//for report catalogs

    QJsonDocument doc(root);
    QJsonArray array;
    foreach (const QVariantHash &reportHash, SingletonConnect::getInstance().getReportDataShortList()) {
        QJsonObject object;
        object = object.fromVariantHash(reportHash);
        array.append(object);
    }

    QJsonDocument fromModel(array);
    qDebug()<<"from mdl"<<fromModel;
    qDebug()<<"from api"<<doc;
    //QString(doc.toJson());version 1
    QString(fromModel.toJson());

    //qDebug()<< QString(doc.toJson(QJsonDocument::Compact));

    data.addQueryItem("data", QString(fromModel.toJson(QJsonDocument::Compact)));

    QJsonObject resp;

    int err = setAPICall("setReport", key, data, resp);//hot point*

    return err;
}

int FreskoAPI::setReportPhoto(int report_id, QDateTime time, int route_id, const QByteArray &image)
{
    QUrlQuery key;
    QUrlQuery data;
    data.addQueryItem("id", QString::number(report_id));
    //data.addQueryItem("photo", base64);
    data.addQueryItem("date", time.toString("dd.MM.yyyy"));
    data.addQueryItem("time", time.toString("hh:mm"));
    data.addQueryItem("route_id", QString::number(route_id));

    QJsonObject resp;

    int err;
    SApiBinaryData img_data;
    img_data.name= "photo";
    img_data.file= "horror-photo-1.jpg";
    img_data.type= JPG_FILE_TIPE;
    img_data.data = image;

    err = setAPICall("setReportPhoto", key, data, resp, &img_data);

    return err;

}

int FreskoAPI::checkIn(int routeID)
{
    QUrlQuery key;
    QUrlQuery data;
    data.addQueryItem("date", QDateTime::currentDateTime().toString("dd.MM.yyyy"));
    data.addQueryItem("time", QDateTime::currentDateTime().toString("hh:mm"));
    data.addQueryItem("route_id", QString::number(routeID));

    QJsonObject resp;

    int err = setAPICall("checkIn", key, data, resp);

    return err;
}

int FreskoAPI::checkOut(int routeID)
{
    QUrlQuery key;
    QUrlQuery data;
    data.addQueryItem("date", QDateTime::currentDateTime().toString("dd.MM.yyyy"));
    data.addQueryItem("time", QDateTime::currentDateTime().toString("hh:mm"));
    data.addQueryItem("route_id", QString::number(routeID));

    QJsonObject resp;

    int err = setAPICall("checkOut", key, data, resp);

    return err;
}

int FreskoAPI::getComments(QDate from_date, QDate to_date, QVector<SCommentsListEntry>& out)
{
    QUrlQuery data;
    data.addQueryItem("from_date", from_date.toString("dd.MM.yyyy"));
    data.addQueryItem("to_date", to_date.toString("dd.MM.yyyy"));
    QJsonObject resp;
    out.clear();

    int err = getAPICall("getComments", data, resp);

    if (NO_ERROR != err)
    {
        if (5 == err)
            return NO_ERROR;
        else
            return err;
    }

    if (!resp.contains("commentsList")) return NO_ERROR;

    JSON_ARRAY(resp, comments, "commentsList");

    for(int i=0; i<comments.size(); i++)
    {
        SCommentsListEntry entry;
        QJsonObject el = comments[i].toObject();
        JSON_FIELD(el, "rid", entry.report_id).toString().toInt();
        JSON_FIELD(el, "comment", entry.lastText).toString();

        //JSON_FIELS(el, "")
        out.push_back(entry);
    }


    return err;
}

int FreskoAPI::getCommentByReportId(int report_id, QVector<SComment> &out)
{
    QUrlQuery data;
    data.addQueryItem("report_id", QString::number(report_id));
    QJsonObject resp;
    out.clear();

    int err = getAPICall("getCommentByReportId", data, resp);

    if ((NO_ERROR != err))
        return (5 != err)?err:NO_ERROR;

    JSON_ARRAY(resp, comments, "CommentByReportId");

    for(int i=0; i<comments.size(); i++)
    {
        SComment entry;
        entry.reportID = report_id;
        QJsonObject el = comments[i].toObject();
        QString date_time;
        JSON_FIELD(el, "datetime",date_time).toString();
        entry.time = QDateTime::fromString(date_time, "yyyy-MM-dd hh:mm");
        QStringList p1=date_time.split(" ");
        QStringList d = p1[0].split("-");
        entry.time.setDate(QDate( d[0].toInt(), d[1].toInt(), d[2].toInt() ));
        QStringList t = p1[1].split(":");
        entry.time.setTime(QTime( t[0].toInt(), t[1].toInt() ));
        JSON_FIELD(el, "comment", entry.text).toString();

        out.push_back(entry);
    }

    return err;
}

int FreskoAPI::addComment(int report_id, Fesko::SComment comment)
{
    QUrlQuery key;
    QUrlQuery data;
    data.addQueryItem("date", comment.time.toString("dd.MM.yyyy"));
    data.addQueryItem("time", comment.time.toString("hh:mm"));
    data.addQueryItem("text", comment.text);

    key.addQueryItem("report_id", QString::number(report_id));

    QJsonObject resp;

    int err = setAPICall("addComment", key, data, resp);

    return err;
}

int FreskoAPI::getTasks(TTasks& out)
{
    QUrlQuery data;
    QJsonObject resp;

    out.clear();

    int err = getAPICall("getTasks", data, resp);
    if ((NO_ERROR != err))
        return ((6 != err)&&(ERR_SRV_NO_DATA != err))?err:NO_ERROR;

    QString tmp;
    JSON_ARRAY(resp, tasks, "tasks");
    for(int i=0; i<tasks.size(); i++)
    {
        STask entry;
        QJsonObject el = tasks[i].toObject();
        JSON_FIELD_REQIRED(el, "report", entry.report).toString().toInt();
        JSON_FIELD_REQIRED(el, "date", tmp).toString();
        entry.date = QDate::fromString(tmp, "yyyy-MM-dd");
        JSON_FIELD_REQIRED(el, "shop", entry.shop).toString();
        JSON_FIELD_REQIRED(el, "adress", entry.adress).toString();
        JSON_FIELD_REQIRED(el, "city", entry.city).toString();
        JSON_FIELD_REQIRED(el, "autor", entry.autor).toString();
        JSON_FIELD_REQIRED(el, "client", entry.client).toString();
        JSON_FIELD_REQIRED(el, "client", entry.client).toString();
        JSON_FIELD_REQIRED(el, "id", entry.id).toString().toInt();
        JSON_FIELD_REQIRED(el, "task", entry.task).toString();
        int status;
        JSON_FIELD_REQIRED(el, "status",status).toString().toInt();
        entry.status = (ETaskState) status;
        out.push_back(entry);
    }


    return NO_ERROR;
}

int FreskoAPI::reportByTask(STask task, int days)
{
    QDate date = QDate::currentDate();
    for (int i=0; i<days; i++)
    {
        TRoutes routes;
        int err = getRoutes(date, routes);
        date.addDays(1);
        if (NO_ERROR != err) continue;
        for (int j=0; j<routes.size(); j++)
        {
            if (task.city != routes[j].city) continue;
            if (task.shop != routes[j].shop) continue;
            if (task.adress != routes[j].address) continue;

            TShopReports reports;
            err = getShopReports(date, routes[j].id, reports);
            for (int k=0; k<reports.size(); k++)
            {
                if (reports[k].client == task.client)
                    return reports[k].id;
            }//for k
        }//for j
    }//for i
    return -1;
}

int FreskoAPI::getArchivments(TArchivments& out)
{
    QUrlQuery data;
    QJsonObject resp;

    out.clear();

    int err = getAPICall("getArchivments", data, resp);
    if ((NO_ERROR != err))
        return err;

    //TODO: remove this bug workaround
    if (!resp.contains("arch_list")) return NO_ERROR;

    JSON_ARRAY(resp, arch_list, "arch_list");
    for(int i=0; i<arch_list.size(); i++)
    {
        SArchivment entry;
        QJsonObject el = arch_list[i].toObject();
        QString tmp;

        JSON_FIELD(el, "type", entry.type).toString().toInt();
        JSON_FIELD(el, "shopid", entry.shopid).toString().toInt();
        JSON_FIELD(el, "clienttn", entry.clienttn).toString().toInt();
        JSON_FIELD(el, "status", entry.status).toString().toInt();
        JSON_FIELD(el, "dt", tmp).toString();
        entry.dt = QDate::fromString(tmp, "yyyy-MM-dd");
        JSON_FIELD(el, "descr", entry.descr).toString();
        JSON_FIELD(el, "shop", entry.shop).toString();
        JSON_FIELD(el, "city", entry.city).toString();
        JSON_FIELD(el, "address", entry.address).toString();
        JSON_FIELD(el, "client", entry.client).toString();
        JSON_FIELD(el, "type_name", entry.type_name).toString();
        JSON_FIELD(el, "type_sname", entry.type_sname).toString();

        out.push_back(entry);
        /*
         *     int type;
    int shopid;
    int clienttn;
    int status;
    QDate dt;
    QString descr;
    QString shop;
    QString city;
    QString address;
    QString client;*/
    }

    return NO_ERROR;
}

int FreskoAPI::setEmptyReport(int id)
{
    QUrlQuery key;
    QUrlQuery data;
    data.addQueryItem("id", QString::number(id));

    QJsonObject resp;

    int err = setAPICall("setEmptyReport", key, data, resp);

    return err;
}

int FreskoAPI::sendRaw(SStoredRawData& rawdata)
{
    QUrlQuery key(rawdata.key);
    QUrlQuery data(rawdata.data);

    QJsonObject resp;

    int ret;
    if (rawdata.binary.isEmpty())
    {
        ret = setAPICall(rawdata.method, key, data, resp);
    }
    else
    {
        ret = setAPICall(rawdata.method, key, data, resp, &rawdata.binary);
    }

    return ret;
}

int FreskoAPI::getRoutes(QDate date, QVector<SRouteEntry>& out)
{
    QUrlQuery q;
    QJsonObject resp;
    out.clear();

    q.addQueryItem("date",date.toString("yyyy-MM-dd"));
    int err = getAPICall("getShopList", q, resp);

    if (err == 5)
    {
        return NO_ERROR;
    }

    if ((err != 0))
    {
        //Error code 5 means just no results for that date
        return err;
    }

    JSON_ARRAY(resp, loc_array, "shopList")

    for(int i=0; i<loc_array.size(); i++)
    {
        QJsonObject el = loc_array[i].toObject();
        SRouteEntry entry;
        entry.date = date;
        JSON_FIELD(el, "id", entry.id).toString().toInt();
        JSON_FIELD(el, "region", entry.region).toString();
        JSON_FIELD(el, "city", entry.city).toString();
        JSON_FIELD(el, "address", entry.address).toString();
        JSON_FIELD(el, "shop", entry.shop).toString();
        JSON_FIELD(el, "sp_height", entry.pos_long).toString().toDouble();
        JSON_FIELD(el, "sp_width", entry.pos_alt).toString().toDouble();
        out.push_back(entry);
    }

    return NO_ERROR;
}


