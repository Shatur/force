#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QString>
#include <QUrlQuery>
#include <QJsonObject>
#include <QByteArray>

#include "datatypes.h"
#include "datacache.h"
#include "singletonconnect.h"

namespace Fesko
{

class BaseDataProvider
{
public:
    BaseDataProvider():cache(NULL){;};

    int login(QString login, QString password);
    int getData(QString method, QUrlQuery params, QJsonObject &resp);
    int setData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData* data = NULL);

    void setCache(BaseDataCache* c);

    static QByteArray paramsToString(QUrlQuery params, QString& data1);

protected:
    virtual int doLogin(QString login, QString password)=0;
    virtual int doGetData(QString method, QUrlQuery params, QString &resp)=0;
    virtual int doSetData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData* data, QString &resp)=0;

private:
    BaseDataCache* cache;
};

}
#endif // DATAPROVIDER_H
