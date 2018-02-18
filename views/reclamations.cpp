#include "reclamations.h"
#include "ui_reclamations.h"

#include "widgets/reclamation.h"

#include "viewmanager.h"
#include "uihelper.h"

Reclamations::Reclamations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reclamations)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->currentList);
    uiHelper.setupListWidget(ui->fixedList);
    uiHelper.setupListWidget(ui->finalList);

    int tabHeight = (int) uiHelper.viewProperties().winHeight * 0.1;
    int tabWidth = uiHelper.viewProperties().winWidth /3 - 6;
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { height: %1px; width: %2px;}")
                                 .arg(tabHeight).arg(tabWidth));
}

Reclamations::~Reclamations()
{
    delete ui;
}

void Reclamations::setup(Fesko::SReclamations &r)
{
    setupList(ui->currentList, r.curr);
    setupList(ui->fixedList, r.fixed);
    setupList(ui->finalList, r.final);
}

void Reclamations::on_backButton_clicked()
{
    views.pop();
}

void Reclamations::setupList(QListWidget *list, QVector<Fesko::SReclamation> &r)
{
    for(int i=0; i<r.size(); i++)
    {
        uiHelper.addWidgetToList(list, new Reclamation(r[i], this));
    }
}
