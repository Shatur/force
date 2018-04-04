#ifndef COMMENT_H
#define COMMENT_H

#include <QAbstractListModel>

class Comment : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Comment(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // COMMENT_H