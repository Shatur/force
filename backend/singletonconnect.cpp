#include "singletonconnect.h"


QString* SingletonConnect::getReportData()
{
    return &catalogsData;
}

void SingletonConnect::setReportData(const QString &value)
{
    catalogsData = value;
}

QList<QVariantHash> SingletonConnect::getReportDataShortList() const
{
    return reportDataShortList;
}

void SingletonConnect::appendReportDataShortToList(const QVariantHash &value)
{
    reportDataShortList.append(value);

}

