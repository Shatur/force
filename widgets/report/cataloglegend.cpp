#include "cataloglegend.h"
#include "ui_cataloglegend.h"
#include "backend/sqldataprovider.h"

#include "uihelper.h"

#include <QLabel>

CatalogLegend::CatalogLegend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CatalogLegend)
{
    ui->setupUi(this);
}

CatalogLegend::~CatalogLegend()
{
    delete ui;
}

void CatalogLegend::setup(Fesko::SCatalog *cat)
{
    int width = uiHelper.viewProperties().winWidth - 5;
    int fontSize = Fesko::sql_provider()->fontSize();

    for(int i=0; i<cat->staticReportFields.size(); i++)//російською мовою назви категорій не в тренд
    {
        QLabel* name_lbl = new QLabel(this);
        QFont f = name_lbl->font();
        f.setPixelSize(fontSize);
        name_lbl->setFont(f);
        name_lbl->setText(cat->staticReportFields[i]+":");
        name_lbl->setMaximumWidth(width/2);
        name_lbl->setWordWrap(true);
        ui->staticItemsLayout->addWidget(name_lbl);
    }
    for(int i=0; i<cat->reportFields.size(); i++)
    {
        QLabel* name_lbl = new QLabel(this);
        QFont f = name_lbl->font();
        f.setPixelSize(fontSize);
        name_lbl->setFont(f);
        name_lbl->setText(cat->reportFields[i]+":");
        name_lbl->setMaximumWidth(width/2);
        name_lbl->setWordWrap(true);
        ui->dynamicItemsLayout->addWidget(name_lbl);
    }
    //ui->staticItemsLayout
}
