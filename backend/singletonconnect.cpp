#include "singletonconnect.h"


QString* SingletonConnect::getReportData()
{
    return &catalogsData;
}

QString *SingletonConnect::getCommentData()
{
    return &commentData;
}

void SingletonConnect::setReportData(const QString &value)
{
    catalogsData = value;
}

void SingletonConnect::setCommentData(const QString &value)
{
    qDebug()<<101;
    commentData = value;
}

QList<QVariantHash> SingletonConnect::getReportDataShortList() const
{
    return reportDataShortList;
}

void SingletonConnect::appendReportDataShortToList(const QVariantHash &value)
{
    reportDataShortList.append(value);

}

