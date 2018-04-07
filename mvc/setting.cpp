#include "setting.h"

Setting::Setting(QObject *parent)
        : QAbstractListModel(parent)
{
    connect(&SingletonConnect::getInstance(),&SingletonConnect::needSettingAction,
            this, &Setting::recieverSlot);//надає зв'язування із шиною обміна даними
    listSettingFill();
}

Setting::~Setting()
{
    QString _s;
    _s.append("write");
    _s.append("?");
    _s.append(packSettingString());
    SingletonConnect::getInstance().needFileAction( _s );
}

int Setting::rowCount(const QModelIndex &parent) const
{
    return 0;
    if (parent.isValid())
        return 0;
}

QVariant Setting::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case FontSize:
        return QVariant(settingList.value("fontSize"));
    }

    return QVariant();
}

QHash<int, QByteArray> Setting::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[FontSize] = "fontSize";
    return roles;
}

void Setting::setSetting(QString a)
{
    settingList[a.split("=").first()] = a.split("=").last();
}

QVariant Setting::getSetting(QString a)
{
    return QVariant(settingList.value(a));
}

void Setting::recieverSlot(QString a)
{
        parseSettingString(a);
}

QString Setting::packSettingString()
{
    QString _s;
    foreach (auto _v, settingList.keys()) {
        _s.append(_v);
        _s.append("=");
        _s.append(settingList.value(_v));
        _s.append(" ");
    }
    _s.chop(1);
    return _s;
    //формує із данних строку
}

void Setting::parseSettingString(QString a)
{
    QList<QString> _list;
    _list = a.split(" ");
    foreach(auto _v, _list){
      settingList.insert(_v.split("=").at(0),_v.split("=").at(1));
    }
    //формую дані із строки
}

void Setting::listSettingFill()
{
    emit SingletonConnect::getInstance().needFileAction("read");//запрос
    //на етапі ініціалізації заповнює модель
}
