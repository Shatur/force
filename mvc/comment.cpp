#include "comment.h"

Comment::Comment(QObject *parent)
    : QAbstractListModel(parent)
{
}

int Comment::rowCount(const QModelIndex &parent) const
{
    return modelData.size();
    if (parent.isValid())
        return 0;
}

QVariant Comment::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case DateTime:
        return QVariant(modelData[index.row()].dateTime);
    case TextValue:
        return QVariant(modelData[index.row()].textValue);
    case ReadStatus:
        return QVariant(modelData[index.row()].readStatus);
    }

    return QVariant();
}

void Comment::setComment(QDateTime &dt, QString &text, bool &status)
{
    CommentItem _cmn;
    _cmn.dateTime = dt;
    _cmn.textValue = text;
    _cmn.readStatus = status;
    modelData.append(_cmn);
}

QHash<int, QByteArray> Comment::roleNames() const
{
   QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    if (modelData.isEmpty())
        return roles;

    roles[DateTime] = "dateTime";
    roles[TextValue] = "textValue";
    roles[ReadStatus] = "readStatus";
    return roles;
}

void Comment::setReportId(int a)
{
    reportId = a;
}

void Comment::setCommentTextValue(QString a)
{
    bufferString = a;
}

void Comment::addComment(QVariant v)
{
       Fesko::SComment comment;
       comment.text = bufferString;
       comment.time = QDateTime::currentDateTime();
       comment.reportID = reportId;

    Fesko::API.addComment(reportId, comment);
    Fesko::unreadComments()->markNewAsRead(comment);

    QDateTime _dt;
    _dt = QDateTime::currentDateTime();
    bool _s = true;
    CommentItem _cmn;
    _cmn.dateTime = _dt;
    _cmn.textValue = bufferString;
    _cmn.readStatus = _s;

    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    modelData.append(_cmn);
    bufferString = "";
    endInsertRows();
}

void Comment::reciverSlot(QString a)
{
    if(a.contains("add"))
        addComment(a);
}

void Comment::dataExam()
{

}
