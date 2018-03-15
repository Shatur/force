#include "routeitemwidget.h"
#include "ui_routeitemwidget.h"

#include "app_features.h"
#include "viewmanager.h"
#include "views/selectbrand.h"

#include "camera/cam_imgpreocessor.h"

#include "gps.h"
#include "app_features.h"

#include <QMessageBox>
#include <QDateTime>
#include <QDate>
#include <QIcon>



RouteItemWidget::RouteItemWidget(Fesko::SRouteEntry entry, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RouteItemWidget)
{
    ui->setupUi(this);

    ui->regionLbl->setText(entry.region);
    ui->cityLbl->setText(entry.city);
    ui->shopLbl->setText(entry.shop);
    ui->addressLbl->setText(entry.address);

    data = entry;

    isReadOnly = false;

#ifndef DISABLE_REPORT_EDIT_DATE
    int days=QDate::currentDate().daysTo(data.date);
    if (days<0)
    {
        isReadOnly = (days != -1) || (QDateTime::currentDateTime().time().hour() >= 9);
    }

    if (isReadOnly)
    {
        ui->doReportBtn->setText("Переглянути");
        ui->doReportBtn->setIcon(QIcon(":/pics/view_report.png"));
    }
#endif
}

void RouteItemWidget::setup(Fesko::SRouteEntry entry)
{
    ui->regionLbl->setText(entry.region);
    ui->cityLbl->setText(entry.city);
    ui->shopLbl->setText(entry.shop);
    ui->addressLbl->setText(entry.address);

    data = entry;

#ifndef DISABLE_REPORT_EDIT_DATE
    int days=QDate::currentDate().daysTo(data.date);
    if (days<0)
    {
        isReadOnly = (days != -1) || (QDateTime::currentDateTime().time().hour() >= 9);
    }

    if (isReadOnly)
    {
        ui->doReportBtn->setText("Переглянути");
        ui->doReportBtn->setIcon(QIcon(":/pics/view_report.png"));
    }
#endif

}

RouteItemWidget::~RouteItemWidget()
{
    delete ui;
}

void RouteItemWidget::on_doReportBtn_clicked()//перевірка за меж досяжності по ЖПС
{
    int dist = gps::ref().distanceTo(data.pos_alt, data.pos_long);

    if (!isReadOnly)
    {
        if (dist<0)
        {
            QMessageBox msgBox;
            msgBox.setText("Поточні координати недоступні або застарілі\n Увімкніть GPS\nЗвіт буде відкрито лише для перегляду");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
#ifndef DISABLE_GPS_RULE
            isReadOnly = true;//hot point
#endif
        }
        else
        if (dist>MAX_DISTANCE)
        {
            QMessageBox msgBox;
            QString msg = QString("Ви знаходитеся занадто далеко від місця призначення %1\nЗвіт буде відкрито лише для перегляду").arg(dist);
            msgBox.setText(msg);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
#ifndef DISABLE_GPS_RULE
            isReadOnly = true;//hot point toooooooooo
#endif
        }
    }

    setCameraImgText(QString("%1:%2").arg(QString::number(data.pos_alt))
                                     .arg(QString::number(data.pos_long)));

    SelectBrand* wgt = new SelectBrand(NULL);

    if (wgt->setup(data.date, data.id, isReadOnly))
        views.push(wgt);
    else delete wgt;
}
