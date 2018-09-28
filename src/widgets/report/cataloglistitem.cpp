#include "cataloglistitem.h"
#include "ui_cataloglistitem.h"
#include "backend/sqldataprovider.h"

#include "uihelper.h"

CatalogListItem::CatalogListItem(QString name, QString rules, bool isRO, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CatalogListItem)
{
    ui->setupUi(this);
    int fontSize = Fesko::sql_provider()->fontSize();

    ui->nameLabel->setText(name+"*");//Ім'я бренду
    QFont f = ui->nameLabel->font();
    f.setPixelSize(fontSize);
    ui->nameLabel->setFont(f);
    ui->ruleLbl->setText(rules);// Якісь правила?
    f = ui->ruleLbl->font();
    f.setPixelSize(fontSize);
    ui->ruleLbl->setFont(f);
    ui->ruleLbl->setMaximumWidth(uiHelper.viewProperties().winWidth - 15);
}

CatalogListItem::~CatalogListItem()
{
    delete ui;
}
