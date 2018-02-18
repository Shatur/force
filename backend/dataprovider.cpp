#include "dataprovider.h"

#include "datatypes.h"
#include <QDebug>
#include <QJsonDocument>
#include <QSet>

static QSet<QString> ignoredAPI = QSet<QString>()<<"checkIn"<<"checkOut";

const QString boundary = "popikih7swxAsrf456BGe4h";

int Fesko::BaseDataProvider::login(QString login, QString password)
{
    int retVal = doLogin(login, password);
    if (NO_ERROR != retVal)
    {
        qDebug()<<"provider RetVal is "<<retVal;
        return retVal;
    }
    /*if (cache)
    {
        cache->cacheLogin(login, password);
    }*/

    return retVal;
}

int Fesko::BaseDataProvider::getData(QString method, QUrlQuery params, QJsonObject &resp)
{
    QString str_response;
    int retVal = doGetData(method, params, str_response);

    if (NO_ERROR != retVal)
    {
        return retVal;
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(str_response.toUtf8());
    resp = jsonResponse.object();    

    SingletonConnect::getInstance().setReportData(str_response);
    if (resp.contains("err"))
    {
        if (resp.contains("code"))
        {
           return resp["code"].toString().toInt();
        }//if we have a code
    }//if error

    /*if (cache)
     *
    {
        cache->cacheGetData(method, params, str_response);
    }*/

    return NO_ERROR;
}

int Fesko::BaseDataProvider::setData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData* data)
{
    QString str_response;
    int retVal = doSetData(method, key, params, data, str_response);

    if (NO_ERROR != retVal)
    {
        return retVal;
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(str_response.toUtf8());
    QJsonObject resp = jsonResponse.object();

    if (ignoredAPI.contains(method)) return NO_ERROR;

    if (resp.contains("err"))
    {
        if (resp.contains("code"))
        {
           return resp["code"].toString().toInt();
        }//if we have a code
    }//if error

    return NO_ERROR;
}

void Fesko::BaseDataProvider::setCache(BaseDataCache *c)
{
    cache = c;
}

QByteArray Fesko::BaseDataProvider::paramsToString(QUrlQuery params, QString &data1)
{

    if (!data1.length())
        return params.toString().toUtf8();
    //const QString boundary = "popikih7swxAsrf456BGe4h";
    QString str;
    QByteArray RetVal;
    QList<QPair<QString, QString> > items = params.queryItems();
    for (int i=0; i<items.size(); i++)
    {
        if (!i) str+="\r\n";
        str+=QString("--")+boundary+"\r\n";
        str+=QString("Content-Disposition: form-data; name=\"")+items[i].first+"\"\r\n";
        str+="\r\n";
        str+=items[i].second+"\r\n";
    }
    \
    str+=QString("--")+boundary+"\r\n";
    str+=QString("Content-Disposition: form-data; name=\"photo\"; filename=\"horror-photo-1.jpg\"\r\n");
    str+=QString("Content-Type: image/jpeg\r\n");
    str+="\r\n";
    RetVal = str.toUtf8();
    QByteArray ba(data1.toUtf8());
    RetVal.append(QByteArray::fromBase64(data1.toUtf8()));
    RetVal.append("\r\n\r\n");
    RetVal.append(QString("--")+boundary+"--\r\n\r\n");
    //RetVal+=data1+"\r\n";
    //RetVal+=QString("--")+boundary+"\r\n\r\n";


    return RetVal;
}

