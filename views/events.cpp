#include "events.h"
#include "ui_events.h"

#include "widgets/eventitemwidget.h"
#include "uihelper.h"
#include "viewmanager.h"
#include "views/errordialog.h"

#include <QScroller>
#include <QListWidgetItem>
#include <QTimer>

Events::Events(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Events)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->ev_spaceList);
    uiHelper.setupListWidget(ui->ev_actionList);
    uiHelper.setupListWidget(ui->ev_target_taskList);

    int tabHeight = (int) uiHelper.viewProperties().winHeight * 0.1;
    int tabWidth = uiHelper.viewProperties().winWidth /3 - 6;
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { height: %1px; width: %2px;}")
                                 .arg(tabHeight).arg(tabWidth));
}

Events::~Events()
{
    delete ui;
}

bool Events::setup()
{
    SHOW_WAITING_DIALOG;

    int err = Fesko::API.getEvents(ev_space, Fesko::etAdditioonalSpace);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }
    err = Fesko::API.getEvents(ev_target_task, Fesko::etTargetTask);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }
    err = Fesko::API.getEvents(ev_action, Fesko::etAction);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }

    //ui->eventsList->clear();
    for (int i=0; i<ev_space.size(); i++)
    {
        if (ev_space[i].to_date >= QDate::currentDate())
            uiHelper.addWidgetToList(ui->ev_spaceList,
                                     new EventItemWidget(ev_space[i]));
    }

    for (int i=0; i<ev_target_task.size(); i++)
    {
        if (ev_target_task[i].to_date >= QDate::currentDate())
            uiHelper.addWidgetToList(ui->ev_target_taskList,
                                     new EventItemWidget(ev_target_task[i]));
    }

    for (int i=0; i<ev_action.size(); i++)
    {
        if (ev_action[i].to_date >= QDate::currentDate())
            uiHelper.addWidgetToList(ui->ev_actionList,
                                     new EventItemWidget(ev_action[i]));
    }
    return true;
}

void Events::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

}

void Events::resizeItems()
{

}

void Events::on_backButton_clicked()
{
    views.pop();
}
