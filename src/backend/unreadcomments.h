#ifndef UNREADCOMMENTS_H
#define UNREADCOMMENTS_H

#include "datatypes.h"

#include <QSet>
#include <QMap>

namespace Fesko
{

typedef struct _SReportUnreadComments
{
    int allCount;
    int UnreadCount;
    _SReportUnreadComments()
    {
        allCount = 0;
        UnreadCount = 0;
    }
}SReportUnreadComments;

class UnreadComments
{
public:
    UnreadComments();
    virtual ~UnreadComments();

    bool read();
    void flush();
    void clear();

    void beginAddComments();
    void addComments(TReportComments &comments);
    void doneAddComments();

    void markAsRead(TReportComments& comments);
    void markAsRead(SComment& comment);
    void markNewAsRead(SComment& comment);

    SReportUnreadComments unreadByReport(int reportID);
    SReportUnreadComments checkComments(TReportComments& comments);
    bool checkComment(SComment& comment);

private:
    QSet<QString> set;
    QSet<QString> curr_set;

    QMap<int, SReportUnreadComments> commentsByReport;

    QString commentHash(const SComment& comment)
    {
        return QString::number(comment.reportID) + comment.time.toString()+comment.text;
    }

    void markAsRead(SComment& comment, bool isNew);
};
    UnreadComments* unreadComments();
} // Fesko namespace
#endif // UNREADCOMMENTS_H
