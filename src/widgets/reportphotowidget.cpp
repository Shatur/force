#include "reportphotowidget.h"
#include "ui_reportphotowidget.h"

#include "uihelper.h"

#include <QPixmap>
#include <QDateTime>
#include <QStandardPaths>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QBuffer>
#include <QFile>

ReportPhotoWidget::ReportPhotoWidget(const QImage &_img, QString file, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportPhotoWidget)
{
    ui->setupUi(this);

    imgTime = QDateTime::currentDateTime();
    img_file = file;

    img = _img;

    ui->photo->setPixmap(QPixmap::fromImage(img));
    this->setMaximumWidth(uiHelper.viewProperties().winWidth);
    float h = uiHelper.viewProperties().winHeight;
    h = (h - 2*h*.20) / 4;
    int hi = (int)h;
    this->setMinimumHeight(hi);
    connect(ui->photo, SIGNAL(clicked()), this, SLOT(photoCliched()));
}

ReportPhotoWidget::~ReportPhotoWidget()
{
    QFile file(img_file);
    //file.remove();
    delete ui;
}

void ReportPhotoWidget::getBASE64(QString &outImg, QDateTime &time)
{
    QByteArray ba;
    QBuffer buff(&ba);
    buff.open(QIODevice::WriteOnly);
    img.save(&buff,"JPG");
    outImg = ba.toBase64(/*QByteArray::Base64UrlEncoding | QByteArray::OmitTrailingEquals*/);
    //outImg.replace("+","%2B");

    /*QByteArray bb;
    bb.append(outImg);
    QFile f("d:\\img.jpg");
    f.open(QIODevice::WriteOnly);
    f.write(QByteArray::fromBase64(bb));*/
}

void ReportPhotoWidget::getPhoto(QByteArray &ba, QDateTime &time)
{
    QBuffer buff(&ba);
    buff.open(QIODevice::WriteOnly);
    img.save(&buff,"JPG");
}

void ReportPhotoWidget::on_removeBtn_clicked()
{
    /*delete myItem;
    this->deleteLater();*/
    emit deletePressed();
}

void ReportPhotoWidget::photoCliched()
{
    /*QString dir = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).last();//Qt::PicturesLocation

    qDebug()<<dir;

    QString filename;
    filename = QDateTime::currentDateTime().toString("dd_MM_yy_hh_mm.jpg");

    filename = dir + QString("/") + filename;

    qDebug()<<filename;

    img.save(filename, "JPG");

    filename=QString("file:///")+filename;
    QDesktopServices::openUrl(QUrl(filename));*/
    QDesktopServices::openUrl(QString("file:///")+img_file);
}
