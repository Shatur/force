#include "selectbrand.h"
#include "ui_selectbrand.h"

#include "backend/api.h"
#include "views/report.h"

#include <QMessageBox>

SelectBrand::SelectBrand(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectBrand)
{
    ui->setupUi(this);

    views.addObserver(this);
    isReadOnly = false;
    //ui->brandsList->sizeHintForRow();
}

SelectBrand::~SelectBrand()
{
    views.removeObserver(this);
    delete ui;
}

bool SelectBrand::setup(QDate date, int id, bool isRO)
{
    SHOW_WAITING_DIALOG;

    isReadOnly = isRO;

    if (!isReadOnly)
        Fesko::API.checkIn(id);
    else
        ui->backButton->setText("Назад");

    shop_id = id;
    report_date = date;

    int err = Fesko::API.getShopReports(date, id, sr);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_WAITING_DIALOG;
        return false;
    }

    ui->brandsList->clear();

    for (int i=0; i<sr.size(); i++)
    {
        QListWidgetItem* item = new QListWidgetItem(sr[i].client);
        ui->brandsList->addItem(item);

        if (!i)
            ui->brandsList->setCurrentItem(item);
    }

    ui->emptyReportBtn->setVisible(!isRO);

    return true;
}

bool SelectBrand::onViewPop(QWidget *current, bool isKey)
{
    if (current != this) return true;

    if (!isReadOnly)
        Fesko::API.checkOut(shop_id);

    if (!isKey)
        return true;
    QString msg = "Ви покидаєте торгівельну точку. Продовжити?";
    return QMessageBox::Yes == QMessageBox::question(this, "Вихід", msg,
                                                     QMessageBox::Yes|QMessageBox::No);

}

void SelectBrand::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    QSize list_size = ui->brandsList->size() - ui->brandsList->size()*0.1;
    int item_height;// = list_size.height() / 10;
    int divider = 1;
    int items_cnt = ui->brandsList->count();
    if (items_cnt>10)
    {
        divider = 10;
    }
    else if (items_cnt<2)
    {
        divider = 3;
    }
    else
    {
        divider = items_cnt;
    }
    item_height = list_size.height() / divider;

    for(int i=0; i< ui->brandsList->count(); i++)
    {
        QListWidgetItem* item = ui->brandsList->item(i);
        QSize sh = item->sizeHint();
        sh.setHeight(item_height);
        item->setSizeHint(sh);
    }
}

void SelectBrand::on_backButton_clicked()
{
    views.pop();
}

void SelectBrand::on_goReportBtn_clicked()
{    
    int list_idx = ui->brandsList->currentRow();




    if ((list_idx>=0) && (list_idx<sr.size()))
    {
        int idx = sr[list_idx].id;
        Report* wgt = new Report(NULL);
        if (wgt->setup(idx, shop_id, isReadOnly))
            views.push(wgt);
        else delete wgt;
    }

}

void SelectBrand::on_emptyReportBtn_clicked()
{
    int list_idx = ui->brandsList->currentRow();

    if ((list_idx>=0) && (list_idx<sr.size()))
    {
        QString brand = ui->brandsList->currentItem()->text();
        QString msg = QString("Здати порожній звіт для %1? ").arg(brand);
        if (QMessageBox::Yes != QMessageBox::question(this, "Порожній звіт", msg,
                                                        QMessageBox::Yes|QMessageBox::No))
            return;

        int idx = sr[list_idx].id;

        Fesko::API.setEmptyReport(idx);
    }
}
