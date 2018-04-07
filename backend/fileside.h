#ifndef FILESIDE_H
#define FILESIDE_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QDebug>

#include "backend/singletonconnect.h"

class FileSide : public QObject
{
    Q_OBJECT
public:
    explicit FileSide(QObject *parent = nullptr);

signals:

public slots:

private:

    void settingRead();
    void settingWrite(QString);
    void receiverSlot(QString);
    void dataSave(QString);

    QFile settingFile;


};

#endif // FILESIDE_H
