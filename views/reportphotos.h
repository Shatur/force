#ifndef REPORTPHOTOS_H
#define REPORTPHOTOS_H

#include <QWidget>
#include <QDateTime>
#include <QVector>
#include <QByteArray>

typedef struct _SPhotoInfo
{
    QDateTime datetime;
    QByteArray photo;
}SPhotoInfo;

namespace Ui {
class ReportPhotos;
}

class ReportPhotos : public QWidget
{
    Q_OBJECT

public:
    explicit ReportPhotos(QWidget *parent = 0);
    ~ReportPhotos();

    int getPhotos(QVector<SPhotoInfo> &out);

private slots:
    void on_addPhotoBtn_clicked();

    void camImageReady(const QImage& image, QString file);

    void onShotDone();

    void itemDeletePressed();

    void on_backButton_clicked();

private:
    Ui::ReportPhotos *ui;
};

#endif // REPORTPHOTOS_H
