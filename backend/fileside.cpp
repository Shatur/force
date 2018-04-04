#include "fileside.h"

FileSide::FileSide(QObject *parent) : QObject(parent)
{
    qDebug()<<QDir::currentPath();
    QFile file("test.txt");

    if (file.open(QIODevice::WriteOnly))
    {
        file.write("Test string\n");
        file.write("Test string2");
        file.close();
    }

    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        while(!file.atEnd())
        {
            str=str+file.readLine();
        }
        qDebug()<<str;
        file.close();
    }
}
