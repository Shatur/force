#include "reportphotos.h"
#include "ui_reportphotos.h"

#include "viewmanager.h"
#include "uihelper.h"
#include "camera/cam_imgpreocessor.h"
#include "widgets/reportphotowidget.h"

#include "version.h"

#include <QTimer>

ReportPhotos::ReportPhotos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportPhotos)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->photosList);

    connect(CameraImage(), SIGNAL(camImageReady(QImage, QString)), this, SLOT(camImageReady(QImage, QString)));
}

ReportPhotos::~ReportPhotos()
{
    delete ui;
}

int ReportPhotos::getPhotos(QVector<SPhotoInfo>& out)
{
    for(int i=0; i<ui->photosList->count(); i++)
    {
        QListWidgetItem* item = ui->photosList->item(i);
        ReportPhotoWidget* wgt = dynamic_cast<ReportPhotoWidget*> (ui->photosList->itemWidget(item));
        if (wgt)
        {
            SPhotoInfo info;
            wgt->getPhoto(info.photo, info.datetime);
            //info.base64=QString("data:image/jpeg;base64,") + info.base64;
            out.push_back(info);
        }
    }

    return 0;
}

void ReportPhotos::on_addPhotoBtn_clicked()
{
    /*static CameraView* cv = 0;
    if (!cv) cv = new CameraView;
    views.push(cv, false);*/

#ifndef DIMA_DEBUG
    views.displayCamera();
#else
    QImage img;
#ifdef Q_WS_WIN
    img.load("d:\\test.jpg");
#else
    img.load("/home/yurkis/test.jpg");
#endif
    camImageReady(img, "");
#endif
}

void ReportPhotos::camImageReady(const QImage &image, QString file)
{
    ReportPhotoWidget* wgt = new ReportPhotoWidget(image, file, this);
    uiHelper.addWidgetToList(ui->photosList, wgt);

    connect(wgt, SIGNAL(deletePressed()), this, SLOT(itemDeletePressed()));

    QTimer::singleShot(1000, this, SLOT(onShotDone()));
}

void ReportPhotos::onShotDone()
{
#ifndef DIMA_DEBUG
   views.backToViews();
#endif
}

void ReportPhotos::itemDeletePressed()
{
    QObject* obj = QObject::sender();
    for(int i=0; i<ui->photosList->count(); i++)
    {
        QListWidgetItem* item= ui->photosList->item(i);

        if (ui->photosList->itemWidget(item) == obj)
        {
            ui->photosList->itemWidget(item)->deleteLater();

            ui->photosList->takeItem(i);

            //delete item;
        }
    }
}

void ReportPhotos::on_backButton_clicked()
{
    views.pop();
}
