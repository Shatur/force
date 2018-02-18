#include "gps.h"

#include <QDebug>

const int VALID_SECCONDS = 60*45; //45 mins

gps::gps(QObject *parent) : QObject(parent)
{
    posSrc = QGeoPositionInfoSource::createDefaultSource(this);
    if (!posSrc)
    {
        qDebug()<<"NO GPS SOURCE!";
        return;
    }
    posSrc->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);
    //posSrc->setUpdateInterval(1000*30);
    connect(posSrc, SIGNAL(positionUpdated(QGeoPositionInfo)),
            this, SLOT(onPositionUpdated(QGeoPositionInfo)));
    posSrc->startUpdates();
    qDebug()<<"GPS init";
}

gps &gps::ref()
{
    static gps* pMe = NULL;
    if (!pMe) pMe = new gps(NULL);
    return *(pMe);
}

int gps::distanceTo(double pos_latitube, double pos_longitude)
{
    if (! coordinate.isValid()) return -1;
    QGeoCoordinate c(pos_latitube, pos_longitude);

    /*if (lastUpdate.secsTo(QDateTime::currentDateTime()) > VALID_SECCONDS)
        return -2;*/

    return (int) coordinate.distanceTo(c);
}

void gps::onPositionUpdated(QGeoPositionInfo info)
{
    qDebug()<<"GPS ==>>Update";
    if (!info.isValid()) return;

    lastUpdate = QDateTime::currentDateTime();

    coordinate = info.coordinate();
    qDebug()<<"GPS ==>>a:"<<coordinate.latitude();
    qDebug()<<"GPS ==>>l:"<<coordinate.longitude();
}
