#ifndef REPORTPHOTOWIDGET_H
#define REPORTPHOTOWIDGET_H

#include <QWidget>

#include <QImage>
#include <QListWidgetItem>
#include <QDateTime>

namespace Ui {
class ReportPhotoWidget;
}

class ReportPhotoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportPhotoWidget(const QImage& _img, QString file, QWidget *parent = 0);
    ~ReportPhotoWidget();

    void getBASE64(QString& outImg, QDateTime& time);
    void getPhoto(QByteArray& ba, QDateTime& time);

signals:
    void deletePressed();

private slots:
    void on_removeBtn_clicked();
    void photoCliched();

private:
    Ui::ReportPhotoWidget *ui;

    QImage img;
    QListWidgetItem* myItem;
    QDateTime imgTime;
    QString img_file;
};

#endif // REPORTPHOTOWIDGET_H
