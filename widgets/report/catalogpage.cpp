#include "catalogpage.h"
#include "ui_catalogpage.h"

#include "widgets/report/cataloglistitem.h"
#include "widgets/report/reportitem.h"

#include "uihelper.h"
#include "mvc/catalog.h"



CatalogPage::CatalogPage(int id, Fesko::SCatalog *cat, bool isRO, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CatalogPage)
{    

    ui->setupUi(this);

    uiHelper.setupListWidget(ui->itemsList);

    ui->legend->setup(cat);

    ui->itemsList->clear();

    uiHelper.addWidgetToList(ui->itemsList,
                             new CatalogListItem(cat->catalogName,
                                                 cat->catalogRule,
                                                 isRO));

    for(int i=0; i<cat->reportItems.size();i++)
    {

        ReportItem* wgt = new ReportItem(i,cat->staticReportFields,
                                         cat->reportFields,
                                         &cat->reportItems[i],
                                         isRO,
                                         NULL);
        //qDebug() << __FILE__ << __LINE__<<__FUNCTION__;

        connect(this, SIGNAL(needUpdate()), wgt, SLOT(updateData()));

        uiHelper.addWidgetToList(ui->itemsList, wgt);
    }
}

CatalogPage::~CatalogPage()
{
    delete ui;
}

void CatalogPage::update()
{
    emit needUpdate();
}

void CatalogPage::dataUpdate()
{
    emit needUpdate();
}
