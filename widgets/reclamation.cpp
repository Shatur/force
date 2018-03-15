#include "reclamation.h"
#include "ui_reclamation.h"

#include "viewmanager.h"
#include "uihelper.h"

#include "views/report.h"

Reclamation::Reclamation(Fesko::SReclamation &r, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reclamation)
{
    ui->setupUi(this);

    ui->cityLbl->setText(r.city);
    ui->dateLbl->setText(r.date.toString());
    ui->addressLbl->setText(r.adress);
    ui->nameLbl->setText(r.name);
    ui->infoLbl->setText(r.info);

    ui->infoLbl->setMaximumWidth(uiHelper.viewProperties().winWidth - 5);
    this->setMaximumWidth(uiHelper.viewProperties().winWidth);

    report_id = r.report;
}

Reclamation::~Reclamation()
{
    delete ui;
}

void Reclamation::on_goReportBtn_clicked()
{
    Report* wgt = new Report(NULL);
    if (wgt->setup(report_id, 0, false))
    {
        views.push(wgt);
    }
    else delete wgt;
}
