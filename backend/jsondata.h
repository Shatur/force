#ifndef JSONDATA_H
#define JSONDATA_H

#include "datatypes.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QString>

namespace Fesko
{
    int fromJSON(QJsonObject resp, SReport& out);
    int fromJSON(QJsonArray obj, QVector<SReportItem>& items);
    int mergeJSON(QJsonArray arr, SReport& report);

    QString reportValFromJsong(QString val, int type);
    QString reportValueToJson(QString val, int type);
}
#endif // JSONDATA_H
