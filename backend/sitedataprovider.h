#ifndef SITEDATAPROVIDER_H
#define SITEDATAPROVIDER_H

#include <QObject>
#include "dataprovider.h"


namespace Fesko
{

class SiteDataProvider : public QObject, public BaseDataProvider
{
    Q_OBJECT
public:
    explicit SiteDataProvider(QObject *parent = 0);
protected:
    virtual int doLogin(QString login, QString password);
    virtual int doGetData(QString method, QUrlQuery params, QString &resp);
    virtual int doSetData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData* data, QString &resp);

signals:

public slots:

private:
    virtual int makePOST(QString script_file, QUrlQuery params, SApiBinaryData* data, QString &resp);

    virtual void makePayload(QUrlQuery params, SApiBinaryData* data, QByteArray& out);

    QString token;
};
SiteDataProvider* site_provider();
}
#endif // SITEDATAPROVIDER_H
