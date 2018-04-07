#include "fileside.h"

FileSide::FileSide(QObject *parent) : QObject(parent)
{

    connect(&SingletonConnect::getInstance(),&SingletonConnect::needFileAction,
            this, &FileSide::receiverSlot);//надає зв'язування із шиною обмінаданими

    qDebug()<<QDir::currentPath();
    settingFile.setFileName("setting");

}
void FileSide::settingRead()
{
    QString _s="";
    if ((settingFile.exists())&&(settingFile.open(QIODevice::ReadOnly)))
    {
        while(!settingFile.atEnd())
        {
            _s=_s+settingFile.readLine();
        }
        settingFile.close();
        emit SingletonConnect::getInstance().needSettingAction(_s);//ответ
    }
    //читає із потрібного файла
}

void FileSide::settingWrite(QString a)
{
    QByteArray _ba;
    _ba.append(a.split("?").last());

    if (settingFile.open(QIODevice::WriteOnly))
    {
        settingFile.write(QByteArray(_ba));
        settingFile.close();
    }
    //записує у потрібний файл
}

void FileSide::receiverSlot(QString a)
{
    if(a.contains("read"))
        settingRead();
    if(a.contains("write"))
        settingWrite(a);
    if (a.contains("Setting"))
        settingWrite(a);
    //функція приймаю запрос та адресує його
}

void FileSide::dataSave(QString a)
{

}
