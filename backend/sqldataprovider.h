#ifndef SQLDATAPROVIDER_H
#define SQLDATAPROVIDER_H

#include <QObject>

#include "dataprovider.h"
#include "datacache.h"
#include "datatypes.h"

#include <QDate>
#include <QSql>
#include <QSqlDatabase>

namespace Fesko
{


class SQLDataProvider : public QObject, public BaseDataProvider, public BaseDataCache
{
    Q_OBJECT
public:
    explicit SQLDataProvider(QObject *parent = 0);

    virtual void cacheLogin(QString login, QString password);
    virtual void cacheGetData(QString method, QUrlQuery params, const QJsonObject &resp);
    virtual void cacheFontSize(int fontSize);

    int lastLoginDate(QDate &out);
    int lastSyncDate(QDate &out);
    QString lastLogin();
    QString lastPass();
    int fontSize();

    void beginSyncSession();
    void commitSyncSession();
    void rollbackSyncSession();

    bool mergeReport(Fesko::SReport& report);
    bool mergeComments(int report_id, TReportComments& comments);

    int outCount(QString method, QString key);
    int outCount(QString method, QUrlQuery key);

    void clearResponces();

    int rawData(QVector<SStoredRawData>& out);
    int removeRawEntry(int id);

protected:
    virtual int doLogin(QString login, QString password);
    virtual int doGetData(QString method, QUrlQuery params, QString &resp);
    virtual int doSetData(QString method, QUrlQuery key, QUrlQuery params, SApiBinaryData* data, QString &resp);

signals:
    void report(QString);

public slots:

private:
    int prepare_db()
    {
        if (!db.isValid())
        {
            return init();
        }
        return NO_ERROR;
    }

    typedef struct _DBData
    {
        int ver;
        QString currentSet;
        QDate lastLogin;
        QString login;
        QString password;
        QDate lastSync;
        int font_size;
    }DBData;

    DBData dbData;

    int init();
    int openDB();
    int createDB();

    QString dbFileName();

    QSqlDatabase db;
};

SQLDataProvider* sql_provider();
}
#endif // SQLDATAPROVIDER_H
