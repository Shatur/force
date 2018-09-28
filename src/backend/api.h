#ifndef API_H
#define API_H

#include <QObject>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>

#include "datatypes.h"
#include "dataprovider.h"
#include "datacache.h"

namespace Fesko
{

class FreskoAPI : public QObject
{
    Q_OBJECT

    explicit FreskoAPI(QObject *parent = 0);

public:
    static FreskoAPI& ref();

    void setDataProvider(BaseDataProvider* p);
    void setCache(BaseDataCache* c);

    int login(QString login, QString pass);
    int getRoutes(QDate date, TRoutes &out);
    int getShopReports(QDate date, int shopid, TShopReports& reports);
    int getReport2(int id, SReport &out);

    int getEvents(TEvents& out, EEventType et);

    int getReclamList(SReclamations &out);

    int setReport(SReport &report);
    int setReportPhoto(int report_id, QDateTime time, int route_id, const QByteArray& image);
    int checkIn(int routeID);
    int checkOut(int routeID);
    int getComments(QDate from_date, QDate to_date, QVector<SCommentsListEntry> &out);
    int getCommentByReportId(int report_id, QVector<SComment>& out);
    int addComment(int report_id, SComment comment);
    int getTasks(TTasks &out);

    int reportByTask(STask task, int days);

    int getArchivments(TArchivments &out);

    int setEmptyReport(int id);

    int sendRaw(SStoredRawData &rawdata);

protected:

    QString token;

    int getAPICall(QString method, QUrlQuery params, QJsonObject &resp);
    int setAPICall(QString method, QUrlQuery key, QUrlQuery params, QJsonObject &resp, SApiBinaryData *data=NULL);

signals:
    void error(QString msg);

public slots:

private:
    BaseDataProvider* provider;
    BaseDataCache* cache;
};
    static FreskoAPI& API = FreskoAPI::ref();

    QString errorToString(int);
}

#endif // API_H
