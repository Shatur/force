#include "fakedataprovider.h"

#include <QTextStream>

using namespace Fesko;

const char* const DAMP_FILE = "RESTdump.txt";

FakeDataProvider::FakeDataProvider(QObject *parent) : Fesko::SiteDataProvider(parent)
{
    file  = new QFile(DAMP_FILE);
    file->open(QIODevice::ReadWrite | QIODevice::Text );
}

int FakeDataProvider::makePOST(QString script_file, QUrlQuery params, QString &resp)
{
    Q_UNUSED(resp);
    QTextStream stream(file);

    QString str;
    stream<<"\n\n ========= CALL "<<script_file<<" =============\n";
    str = params.toString(QUrl::PrettyDecoded);
    stream<<str<<"\n\n";
    stream.flush();
    file->flush();

    return 0;
}

FakeDataProvider *Fesko::fake_provider()
{
    static FakeDataProvider instance;

    return &instance;
}
