#include "showroute.h"
#include "ui_showroute.h"

#include "uihelper.h"

#include "backend/api.h"

#include "uihelper.h"
#include "viewmanager.h"

#include "widgets/routeitemwidget.h"
#include "views/errordialog.h"

#include <QListWidgetItem>
#include <QScroller>

ShowRoute::ShowRoute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowRoute)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->routesList);
}

ShowRoute::~ShowRoute()
{
    delete ui;
}

bool ShowRoute::displayData(QDate newDate)
{
    SHOW_WAITING_DIALOG;

    date = newDate;

    Fesko::TRoutes routes;

    int err = Fesko::API.getRoutes(date, routes);

    if (Fesko::NO_ERROR != err)
    {
        //ui->txtLabel->setText(QString("Помилка: ")+Fesko::errorToString(err));
        SHOW_ERROR_DIALOG(err);
        return false;
    }

    QString msg;
    if (!routes.size())
    {
        msg = QString("На %1 дані відсутні");
    }
    else
    {
        msg = "%1";
    }
    msg=msg.arg(date.toString());
    ui->txtLabel->setText(msg);

    ui->routesList->clear();
    ui->routesList->setEnabled(routes.size());

    for(int i=0; i<routes.size(); i++)
    {
        RouteItemWidget* rw = new RouteItemWidget(routes[i]);
        uiHelper.addWidgetToList(ui->routesList, rw);
    }

    return true;
}

void ShowRoute::on_prevDayBtn_clicked()
{
    displayData(date.addDays(-1));
}

void ShowRoute::on_newxDayBtn_clicked()
{
    displayData(date.addDays(1));
}

bool ShowRoute::setup()
{
    return displayData(QDate::currentDate());
}

void ShowRoute::on_backButton_clicked()
{
    views.pop();
}
