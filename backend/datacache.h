#ifndef DATACACHE_H
#define DATACACHE_H

#include <QString>

namespace Fesko
{

class BaseDataCache
{
public:
    virtual void cacheLogin(QString login, QString password)=0;
    virtual void cacheGetData(QString method, QUrlQuery params, const QJsonObject &resp)=0;
};
}
#endif // DATACACHE_H
