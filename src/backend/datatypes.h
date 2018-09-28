#ifndef DATATYPES_H
#define DATATYPES_H

#include <QDate>
#include <QVector>

namespace Fesko
{

const int NO_ERROR = 0;
const int ERR_BAD_LOGIN = 2;
const int ERR_BAD_TOKEN = 3;
const int ERR_SRV_NO_DATA = 5;
const int ERR_NO_RECLAMATIONS = 7;

const int ERR_CONNECT = -1;
const int ERR_PROTOCOL = -2;
const int ERR_INTERNAL_ERROR = -3;
const int ERR_DB_ERROR = -4;

typedef enum{
    eStatic,
    eReport
}EFieldType;

typedef struct _SRouteEntry
{
    int id;
    QDate date;
    QString region;
    QString address;
    QString city;
    QString shop;
    double  pos_alt;
    double  pos_long;
}SRouteEntry;

typedef QVector<SRouteEntry> TRoutes;

typedef struct _SEvent
{
    int id;
    QDate from_date;
    QDate to_date;
    QString client;
    QString name;
    QString descr;
}SEvent;

typedef QVector<SEvent> TEvents;

typedef struct _SReportItemValue
{
    QString value;
    int     type;
}SReportItemValue;

typedef struct _SReportItem
{
    int id;
    QVector<QString> staticValues;
    QVector<SReportItemValue> reportValues;
}SReportItem;

typedef struct _SCatalog
{
    int id;
    QString catalogName;
    QString catalogRule;
    QVector<QString> staticReportFields;
    QVector<QString> reportFields;
    QVector<SReportItem> reportItems;
}SCatalog;

typedef struct _SReport
{
    int id;
    QDate date;
    QString client;
    QString clienttn;
    int clientid;
    QString shop;
    QString city;
    int cityid;
    QString address;
    int shopid;
    double longtitude;
    double latitude;
    QString mr;
    QString sv;
    int status;

    QVector<SCatalog> catalogs;

}SReport;

typedef struct _SShopReportEntry
{
    int id;
    QString client;
    int status;
}SShopReportEntry;

typedef QVector<SShopReportEntry> TShopReports;

typedef struct _SReclamation
{
    int report;
    QDate date;
    QString shop;
    QString adress;
    QString city;
    QString name;
    QString info;
}SReclamation;

typedef struct _SReclamations
{
    QVector<SReclamation> curr;
    QVector<SReclamation> fixed;
    QVector<SReclamation> final;
}SReclamations;

const char* const JPG_FILE_TIPE = "image/jpeg";

typedef struct _SApiBinaryData
{
    QString name;
    QString file;
    QString type;
    QByteArray data;

    bool isEmpty()
    {
        return data.length() == 0;
    }
}SApiBinaryData;

typedef struct _SStoredRawData
{
    int id;
    QString method;
    QString key;
    QString data;

    SApiBinaryData binary;

    _SStoredRawData()
    {
        id = -1;
    }
}SStoredRawData;

typedef enum{
    etAll = 0,
    etAdditioonalSpace,
    etTargetTask,
    etAction,
    etMAX
}EEventType;

typedef struct _SCommentsListEntry
{
    int report_id;
    int count;
    QString lastText;
}SCommentsListEntry;

typedef struct _SComment
{
    QDateTime time;
    QString text;
    bool isUnread;
    int reportID;
    _SComment()
    {
        isUnread = true;
    }
}SComment;

typedef QVector<SComment> TReportComments;

typedef enum
{
    etsUNDONE =0,
    etsWAITING_FOR_CHYECK =1,
    etsCLINET_ACCEPTED =2,
    etsDONE = 3
}ETaskState;

typedef struct _STaks
{
    QString adress;
    QString autor;
    QString city;
    QString client;
    QDate date;
    int id;
    int report;
    QString shop;
    ETaskState status;
    QString task;
}STask;

typedef QVector<STask> TTasks;

typedef struct _SArchivment
{
    QString type_name;
    QString type_sname;
    int type;
    int shopid;
    int clienttn;
    int status;
    QDate dt;
    QString descr;
    QString shop;
    QString city;
    QString address;
    QString client;
}SArchivment;

typedef QVector<SArchivment> TArchivments;

}

#endif // DATATYPES_H
