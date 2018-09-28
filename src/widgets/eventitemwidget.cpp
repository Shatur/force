#include "eventitemwidget.h"
#include "ui_eventitemwidget.h"

#include "uihelper.h"

EventItemWidget::EventItemWidget(Fesko::SEvent ev, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventItemWidget)
{
    ui->setupUi(this);

    ui->startDateLbl->setText(ev.from_date.toString());
    ui->endDateLbl->setText(ev.to_date.toString());
    ui->clientLbl->setText(ev.client);
    ui->nameLbl->setText(ev.name);
    ui->descriptionLbl->setText(ev.descr);
    ui->descriptionLbl->setMaximumWidth(uiHelper.viewProperties().winWidth-5);
}

EventItemWidget::~EventItemWidget()
{
    delete ui;
}

