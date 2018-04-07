#ifndef SETTING_H
#define SETTING_H

#include <QAbstractListModel>
#include <QDateTime>
#include <QDebug>
#include "backend/api.h"
#include "backend/singletonconnect.h"


class Setting : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Setting(QObject *parent = nullptr);
~Setting();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void setSetting(QString);
    Q_INVOKABLE QVariant getSetting(QString);

public slots:
private:
    enum Roles {
          FontSize = Qt::UserRole + 1
    };//задаються ролі по імені яких відображення зв'язанна з моделлю
    struct SettingList{
        int fontSize;
    };//структура данних. Вмежах цьго классу
    QMap<QString,QString>  settingList;//список налаштувань

    void recieverSlot(QString);
    QString packSettingString();
    void parseSettingString(QString);
    void listSettingFill();

};

#endif // COMMENT_H
