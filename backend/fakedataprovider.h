#ifndef FAKEDATAPROVIDER_H
#define FAKEDATAPROVIDER_H

#include <QObject>
#include <QFile>

#include "sitedataprovider.h"

namespace Fesko
{

class FakeDataProvider : public SiteDataProvider
{
    Q_OBJECT
public:
    explicit FakeDataProvider(QObject *parent = 0);

protected:
    virtual int makePOST(QString script_file, QUrlQuery params, QString &resp);

private:
    QFile* file;
};

FakeDataProvider* fake_provider();

}
#endif // FAKEDATAPROVIDER_H
