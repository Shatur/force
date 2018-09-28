#include "tasks.h"
#include "ui_tasks.h"

#include "viewmanager.h"
#include "uihelper.h"
#include "views/errordialog.h"
#include "backend/api.h"
#include "widgets/task.h"

Tasks::Tasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tasks)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->tasksList);
}

Tasks::~Tasks()
{
    delete ui;
}

bool Tasks::setup()
{
    SHOW_WAITING_DIALOG;

    Fesko::TTasks tasks;

    int err = Fesko::API.getTasks(tasks);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }

    for (int i=0; i<tasks.size(); i++)
    {
        uiHelper.addWidgetToList(ui->tasksList, new Task(tasks[i]));
    }

    return true;
}

void Tasks::on_backButton_clicked()
{
    views.pop();
}
