#include "archivment.h"
#include "ui_archivment.h"

#include "uihelper.h"

Archivment::Archivment(Fesko::SArchivment arch, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Archivment)
{
    ui->setupUi(this);

    ui->descrLbl->setMaximumWidth(uiHelper.viewProperties().winWidth -4 );
    this->setMaximumWidth(uiHelper.viewProperties().winWidth - 2 );
    ui->typeLbl->setMaximumWidth(uiHelper.viewProperties().winWidth -4 );

    ui->addressLbl->setText(arch.address);
    ui->cityLbl->setText(arch.city);
    ui->clientLbl->setText(arch.client);
    ui->descrLbl->setText(arch.descr);
    ui->shopLbl->setText(arch.shop);
    ui->typeLbl->setText(QString("(") + arch.type_name + ")");
    ui->type_sLbl->setText(arch.type_sname);
    QString stat;
    QString style;
    switch(arch.status)
    {
        case 0:
            stat = "Очікує на перевірку";
            style = "background-color: rgb(255, 255, 127);";
            break;
        case 1:
            stat = "Підтверджено";
            style = "background-color: rgb(85, 255, 127);";
            break;
        case 2:
            stat = "Відхилено";
            style = "background-color: rgb(255, 170, 255);";
            break;
        case 3:
            stat = "Видалено";
            style = "background-color: rgb(200, 200, 200);";
            break;
        default:
            stat = "Невідомо"; break;
    }
    this->setStyleSheet(style);
    ui->statusLbl->setText(stat);
}

Archivment::~Archivment()
{
    delete ui;
}
