#ifndef GPS_H
#define GPS_H

#include <QObject>

#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
#include <QDateTime>

class gps : public QObject
{
    Q_OBJECT

    explicit gps(QObject *parent = 0);
public:
    static gps &ref();
    int distanceTo(double pos_latitube, double pos_longitude);

signals:

public slots:

private slots:
    void onPositionUpdated(QGeoPositionInfo info);

private:
    QGeoPositionInfoSource* posSrc;
    QGeoCoordinate coordinate;
    QDateTime lastUpdate;
};

//static gps& GPS = gps::ref();

#endif // GPS_H
