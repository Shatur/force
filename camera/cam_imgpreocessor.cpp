#include "cam_imgpreocessor.h"
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQuick/QQuickImageProvider>
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QRect>
#include <QFile>
#include <QTransform>
#include <QScreen>
#include <QGuiApplication>
#include <QOrientationSensor>
#include <QOrientationReading>

static CamImageProcessor instance;

static QString local_txt;

static void paintOnImage(QImage& image, QString data2 = QString())
{
    QPainter p;
    p.begin(&image);
    p.setPen( Qt::white );
    p.setBrush(QBrush(Qt::black));

    int h = image.height();
    int w = image.width();

    int maxh = (h>w)?w:h;
    int maxw = (h>w)?h:w;

    int th = (int)(.15 * (float)maxh);
    int tw = (int)(.25 * (float)maxw);

    QRect r(w-tw, h-th, w, h);
    p.drawRect(r);

    QString txt = QString("%1\n%2\n%3").arg(QDateTime::currentDateTime().toString("dd.MM.yy"))
                                          .arg(QDateTime::currentDateTime().toString("HH:mm"))
                                          .arg(local_txt);
    txt=data2 + QString("<<") + txt;

    p.drawText(r, txt);

    //p.begin(&image);

    p.end();
}

CamImageProcessor::CamImageProcessor(QQuickItem *parent)
    : QQuickItem(parent)
{}

void CamImageProcessor::processImage(const QString& path)
{
    QUrl imageUrl(path);
    QQmlEngine* engine = QQmlEngine::contextForObject(this)->engine();
    QQmlImageProviderBase* imageProviderBase = engine->imageProvider(
     imageUrl.host());
    QQuickImageProvider* imageProvider = static_cast<QQuickImageProvider*>(imageProviderBase);//static_cast<QQuickImageProvider>(imageProviderBase);

    QSize imageSize;
    QString imageId = imageUrl.path().remove(0,1);
    QImage image = imageProvider->requestImage(imageId, &imageSize, imageSize);
    if( !image.isNull()) {

        paintOnImage(image);

        CameraImage()->emitImage(image);
    }
}

CamImageSignalEmmiter *CameraImage()
{
    static CamImageSignalEmmiter instance;
    return &instance;
}

CamImageSignalEmmiter::CamImageSignalEmmiter(QObject *parent)
    : QObject(parent)
{}

void CamImageSignalEmmiter::emitImage(const QImage &image)
{
    emit camImageReady(image, QString());
}

void CamImageSignalEmmiter::emitImage(QString path, int orientation)
{
    QImage img(path);
    if (img.isNull())
    {
        qDebug()<<"NULL image";
    }

    int rotation;
    const QScreen *screen = QGuiApplication::primaryScreen();
    const int screenAngle = screen->angleBetween(screen->nativeOrientation(), screen->orientation());
    rotation = (/*orientation - */screenAngle + 90) % 360;
    QOrientationSensor* s = new QOrientationSensor(this);
    int sensor_orientation=0;
    if (s)
    {
        s->start();
        QOrientationReading* r = s->reading();
        if (r)
        {
            QOrientationReading::Orientation o = r->orientation();

            switch(o)
            {
            case QOrientationReading::TopUp:
                sensor_orientation = 0;
                break;
            case QOrientationReading::TopDown:
                sensor_orientation = 180;
                break;
            case QOrientationReading::LeftUp:
                sensor_orientation = 90;
                break;
            case QOrientationReading::RightUp:
                sensor_orientation = 270;
                break;
            };
        }//if r
    }//if s
    rotation = (rotation + sensor_orientation) %360;

    //QTransform rot;
    //rot.rotate(orientation);
    QImage img2 = img.transformed(QTransform().rotate(rotation));

    paintOnImage(img2, /*QString::number(sensor_orientation) + "/"+ QString::number(rotation)*/QString());

    img2.save(path, "JPG");

    emit camImageReady(img2, path);

    delete s;
}

void setCameraImgText(QString text)
{
    local_txt = text;
}
