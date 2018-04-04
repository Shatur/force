#ifndef COMMENT_H
#define COMMENT_H

#include <QAbstractListModel>
#include <QDateTime>
#include <QDebug>
#include "backend/api.h"
#include "backend/sqldataprovider.h"
#include "backend/unreadcomments.h"
class Comment : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Comment(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setComment(QDateTime &dt, QString &text, bool &status);//добавляє коммент в головну структуру
    virtual QHash<int, QByteArray> roleNames() const;

    void setReportId(int);
    Q_INVOKABLE void setCommentTextValue(QString);
    Q_INVOKABLE void addComment(QVariant);
public slots:
    void reciverSlot(QString);
private:
    enum Roles {
        DateTime = Qt::UserRole + 1,
        TextValue,ReadStatus
    };//задаються ролі по імені яких відображення зв'язанна з моделлю
    struct CommentItem{
        QDateTime dateTime;
        QString textValue;
        bool readStatus;
    };//структура данних. Вмежах цьго классу
    int reportId;
    QString bufferString;
    QList<CommentItem> modelData;// голоовні дані
    void dataExam();//вхідні дані оброблюються тут
};

#endif // COMMENT_H
