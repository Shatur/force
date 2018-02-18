#include "unreadcomments.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStandardPaths>
#include <QDebug>

#define UNREAD_COMMENTS_FILE (QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + QString("comments.txt"))

using namespace Fesko;

static UnreadComments instance;

UnreadComments::UnreadComments()
{

}

UnreadComments::~UnreadComments()
{
    flush();
}

bool UnreadComments::read()
{
   set.clear();
   curr_set.clear();
   commentsByReport.clear();

   qDebug()<<"Comments file: "<<QString(UNREAD_COMMENTS_FILE);

   QFile file(UNREAD_COMMENTS_FILE);
   if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
         return false;

   QTextStream ts(&file);

   while (!ts.atEnd())
   {
      QString line = ts.readLine();
      if (!line.length()) continue;
      set.insert(line);
   }
   return true;
}

void UnreadComments::flush()
{
    QFile file(UNREAD_COMMENTS_FILE);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
            return;
    QTextStream ts(&file);

    QSet<QString>::iterator i;
    for (i = set.begin(); i != set.end(); ++i)
        ts << *i <<"\n";
    ts.flush();
    file.flush();
}

void UnreadComments::clear()
{
    QFile file(UNREAD_COMMENTS_FILE);
    file.remove();
    set.clear();
}

void UnreadComments::beginAddComments()
{
    curr_set.clear();
    commentsByReport.clear();
}

void Fesko::UnreadComments::addComments(Fesko::TReportComments& comments)
{
    for(int i=0; i<comments.size(); i++)
    {
        QString hash = commentHash(comments[i]);
        if (set.contains(hash))
        {
            curr_set.insert(hash);
            comments[i].isUnread = false;
        }//if already read

        SReportUnreadComments byReport;
        if (commentsByReport.contains(comments[i].reportID))
            byReport = commentsByReport[comments[i].reportID];
        byReport.allCount++;
        if (comments[i].isUnread)
            byReport.UnreadCount++;
        commentsByReport[comments[i].reportID] = byReport;
    }//for all comments
}

void UnreadComments::doneAddComments()
{
    set = curr_set;
    curr_set.clear();
}

void UnreadComments::markAsRead(TReportComments &comments)
{
    for(int i=0; i<comments.size(); i++)
    {
        markAsRead(comments[i], false);
    }
}

void UnreadComments::markAsRead(SComment &comment)
{
    markAsRead(comment, false);
}

void UnreadComments::markNewAsRead(SComment& comment)
{
    markAsRead(comment, true);
}

SReportUnreadComments UnreadComments::unreadByReport(int reportID)
{
    SReportUnreadComments ret;
    if (commentsByReport.contains(reportID))
        ret = commentsByReport[reportID];
    return ret;
}

SReportUnreadComments UnreadComments::checkComments(TReportComments &comments)
{
    SReportUnreadComments ret;
    for(int i=0; i<comments.size(); i++)
    {
        if (set.contains(commentHash(comments[i])))
        {
            comments[i].isUnread = false;
        }
        else
        {
            ret.UnreadCount++;
        }
        ret.allCount++;
    }
    return ret;
}

bool UnreadComments::checkComment(SComment &comment)
{
    comment.isUnread = ! set.contains(commentHash(comment));
    return comment.isUnread;
}

void UnreadComments::markAsRead(SComment &comment, bool isNew)
{
    comment.isUnread = false;
    QString hash = commentHash(comment);
    set.insert(hash);
    SReportUnreadComments byReport;
    if (commentsByReport.contains(comment.reportID))
        byReport = commentsByReport[comment.reportID];
    if (isNew)
        byReport.allCount++;
    else
        byReport.UnreadCount--;
}

Fesko::UnreadComments* Fesko::unreadComments()
{
    return &instance;
}
