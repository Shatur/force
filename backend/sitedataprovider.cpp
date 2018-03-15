#include "sitedataprovider.h"

#include "common.h"
#include "datatypes.h"
#include "version.h"

#include <QDebug>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QApplication>
#ifdef TEST_BASE
_str_const BASE_URL="popik.fesko.com.ua";
#else
_str_const BASE_URL="tech.fesko.com.ua";
#endif
//_str_const BASE_URL="tech.fesko.com.ua";//"tech.fesko.com.ua";
_str_const LOGIN_SCRIPT="/proj/mobile/login.php";
_str_const ROUTE_SCRIPT="/proj/mobile/route.php";

using namespace Fesko;

const QString boundary = "";

SiteDataProvider* Fesko::site_provider()
{
    static SiteDataProvider instance;
    return &instance;
}

SiteDataProvider::SiteDataProvider(QObject *parent) : QObject(parent)
{

}

int SiteDataProvider::doLogin(QString login, QString password)
{
    QUrlQuery q;
    q.addQueryItem("_action", "userLogin");
    q.addQueryItem("login", login);
    q.addQueryItem("password", password);

    QString string_resp;
    QJsonObject resp;

    int err = makePOST(LOGIN_SCRIPT, q, NULL, string_resp);
    if (NO_ERROR != err)
    {
        return err;
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(string_resp.toUtf8());
    resp = jsonResponse.object();
    qDebug()<<12345;
    qDebug()<<resp;

    if (resp.contains("token"))
    {
        token= resp["token"].toString();
        return NO_ERROR;
    }

    if (resp.contains("err"))
    {
        //lastErr =QUrl::fromPercentEncoding(resp["err"].toString().toUtf8());
        if (resp.contains("code"))
        {

            err = resp["code"].toString().toInt();
            return err+2000;
        }//if we have a code
    }
    return ERR_PROTOCOL;
}

int SiteDataProvider::doGetData(QString method, QUrlQuery params, QString &resp)
{
    params.addQueryItem("_action", method);
    params.addQueryItem("token", token);
    return makePOST(ROUTE_SCRIPT, params, NULL, resp);
}

int SiteDataProvider::doSetData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData *data, QString &resp)
{
    //merge key and params
    QList<QPair<QString, QString> > key_items = key.queryItems();
    for (int i=0; i<key_items.size(); i++)
    {
        params.addQueryItem(key_items[i].first, key_items[i].second);
    }
    params.addQueryItem("_action", method);
    params.addQueryItem("token", token);

    return  makePOST(ROUTE_SCRIPT, params, data, resp);
}

int SiteDataProvider::makePOST(QString script_file, QUrlQuery params, SApiBinaryData *data, QString &resp)
{
    QByteArray reqq;
    makePayload(params, data, reqq);

    QTcpSocket socket;
    QApplication::processEvents();
    socket.connectToHost(BASE_URL,80,QIODevice::ReadWrite);
    if (!socket.waitForConnected(15000))
    {
        return ERR_CONNECT;
    }
    QString req = QString("POST ")+ script_file + " HTTP/1.0\r\n";
    req+=QString("Host: ")+QString(BASE_URL)+"\r\n";
    req+="User-Agent: curl/7.48.0\r\n";
    req+="Accept: */*\r\n";
    req+=QString("Content-Length: ")+QString::number(reqq./*.toUtf8().*/size())+"\r\n";
    if (!data)
        req+="Content-Type: application/x-www-form-urlencoded\r\n";
    else
        req+=QString("Content-Type: multipart/form-data; boundary=")+boundary+"\r\n";
    //req+="enctype=\"multipart/form-data\"\r\n";
    req+="\r\n";

    ///req+=reqq;

    QByteArray toSend(req.toUtf8());
    toSend.append(reqq);


    qDebug()<<"Request: ===";
    qDebug()<<toSend;
    qDebug()<<"----------------";

    socket.write(toSend);

    socket.waitForBytesWritten(30000);

    QString response;

    bool isfin= false;
    while (!isfin)
    {
        QApplication::processEvents();
        isfin = !socket.waitForReadyRead(15000);
        //qDebug()<<"TCP READY_READ";
        response+=QString::fromUtf8(socket.readAll());
    }

    int idx = response.indexOf("\r\n\r\n");
    response = response.right(response.length() - idx);

    qDebug()<<"RESPONSE: ===";
    qDebug()<<response;
    qDebug()<<"\n\n======================\n";

    resp = response;

    return NO_ERROR;
}

void SiteDataProvider::makePayload(QUrlQuery params, SApiBinaryData *data, QByteArray &out)
{
    out.clear();

    //if no data make URL encoded payload
    if (!data)
    {
        out = params.toString().toUtf8();
        return;
    }
    if (data->isEmpty())
    {
        out = params.toString().toUtf8();
        return;
    }

    //if we have a data make multipart/form-data
    QString str;
    // At first add params
    QList<QPair<QString, QString> > items = params.queryItems();
    for (int i=0; i<items.size(); i++)
    {
        if (!i) str+="\r\n";
        str+=QString("--")+boundary+"\r\n";
        str+=QString("Content-Disposition: form-data; name=\"")+items[i].first+"\"\r\n";
        str+="\r\n";
        str+=items[i].second+"\r\n";
    }

    // ..and then binary data
    str+=QString("--")+boundary+"\r\n";
    str+=QString("Content-Disposition: form-data; name=\"%1\"; filename=\"%2\"\r\n").arg(data->name).arg(data->file);
    str+=QString("Content-Type: %1\r\n").arg(data->type);
    str+="\r\n";
    out = str.toUtf8();
    /*QByteArray ba(data1.toUtf8());
    RetVal.append(QByteArray::fromBase64(data1.toUtf8()));*/
    out.append(data->data);
    out.append("\r\n\r\n");
    out.append(QString("--")+boundary+"--\r\n\r\n");

}


