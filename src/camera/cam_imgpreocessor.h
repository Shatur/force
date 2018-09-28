#ifndef CAM_IMGPREOCESSOR_H
#define CAM_IMGPREOCESSOR_H

#include <QObject>
#include <QQuickItem>

#include <QImage>

class CamImageProcessor : public QQuickItem
{
    Q_OBJECT
public:
    explicit CamImageProcessor(QQuickItem *parent = 0);

public slots:
    void processImage(const QString& image);



};

class CamImageSignalEmmiter: public QObject
{
    Q_OBJECT
public:
    explicit CamImageSignalEmmiter(QObject *parent = 0);

    void emitImage(const QImage& image);
public slots:
    void emitImage(QString path, int orientation);

signals:
    void camImageReady(const QImage& image, QString file);

};

CamImageSignalEmmiter *CameraImage();

void setCameraImgText(QString text);

#endif // CAM_IMGPREOCESSOR_H
