#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "viewmanager.h"
#include "views/showroute.h"
#include "views/events.h"
#include "views/reclamations.h"
#include "views/sync.h"
#include "views/errordialog.h"
#include "views/comments.h"
#include "views/tasks.h"
#include "views/archivments.h"
#include "views/settings.h"

#include "backend/sqldataprovider.h"

#include <QFont>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    views.addObserver(this);
    isReclamationsView = false;
}

MainMenu::~MainMenu()
{
    delete ui;
    views.removeObserver(this);
}

void MainMenu::setCaption(QString txt)
{
    ui->AccountLabel->setText(txt);

    Fesko::sql_provider()->outCount("checkIn", "");
}

void MainMenu::setup()
{
    calculateReclamations();
}

void MainMenu::onRestore(QWidget *lastWidget)
{
    //TODO: remove this placeholder
    if (!isReclamationsView) return;
}

void MainMenu::on_routesBtn_clicked()
{
    ShowRoute* wgt = new ShowRoute(NULL);

    if (wgt->setup())
        views.push(wgt);
    else delete wgt;
}

void MainMenu::on_eventsBtn_clicked()
{
    Events* wgt = new Events(NULL);
    if (wgt->setup())
        views.push(wgt);
    else delete wgt;
}

void MainMenu::on_exitBtn_clicked()
{
    views.logout();
}

void MainMenu::on_reclamationBtn_clicked()
{
    isReclamationsView = true;
    Reclamations* r = new Reclamations(this);
    r->setup(reclams);
    views.push(r, this);
}

void MainMenu::on_syncButton_clicked()
{
    Sync* sync = new Sync(this);

    views.push(sync);

    views.disablePop();

    int err = sync->doSync();

    views.enablePop();

    views.pop();

    calculateReclamations();

    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
    }
}

void MainMenu::on_commentsBtn_clicked()
{
    Comments* wgt = new Comments();

    if (wgt->setup())
    {
        views.push(wgt);
    }
    else
    {
        delete wgt;
    }
}

void MainMenu::on_tasksBtn_clicked()
{
    Tasks* wgt = new Tasks();

    if (wgt->setup())
    {
        views.push(wgt);
    }
    else
    {
        delete wgt;
    }
}

void MainMenu::calculateReclamations()
{
    Fesko::API.getReclamList(reclams);

    ui->reclamationBtn->setText(QString("Рекламації (%1/%2/%3)")
                                .arg(reclams.curr.size())
                                .arg(reclams.fixed.size())
                                .arg(reclams.final.size()));
    if (reclams.curr.size())
    {
        QFont font = ui->reclamationBtn->font();
        font.setBold(true);
        ui->reclamationBtn->setFont(font);
    }
}

void MainMenu::on_archivmentsBtn_clicked()
{
    Archivments* wgt = new Archivments();

    if (wgt->setup())
    {
        views.push(wgt);
    }
    else
    {
        delete wgt;
    }
}

void MainMenu::on_settingsBtn_clicked()
{
    Settings* wgt = new Settings();

    views.push(wgt);
}
