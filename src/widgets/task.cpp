#include "task.h"
#include "ui_task.h"

#include "views/report.h"
#include "uihelper.h"

Task::Task(Fesko::STask task, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    ui->taskLbl->setMaximumWidth(uiHelper.viewProperties().winWidth - 4);
    ui->taskLbl->setText(task.task);
    ui->addressLbl->setText(task.adress);
    ui->authorLbl->setText(task.autor);
    ui->clientLbl->setText(task.client);
    ui->cityLbl->setText(task.city);
    ui->dateLbl->setText(task.date.toString());
    ui->shopLbl->setText(task.shop);
    QString state;
    switch(task.status)
    {
        case Fesko::etsUNDONE:
            state = "Не виконана";
            break;
        case Fesko::etsWAITING_FOR_CHYECK:
            state = "Очікує на перевірку";
            break;
        case Fesko::etsCLINET_ACCEPTED:
            state = "Прийнята клієнтом";
            break;
        case Fesko::etsDONE:
            state = "Виконана";
            break;
        default:
            state = "НЕВІДОМО";
            break;
    }
    ui->stateLbl->setText(state);
    myTask = task;

    reportID = Fesko::API.reportByTask(task,2);
    ui->goReportBtn->setVisible(reportID>0);
}

Task::~Task()
{
    delete ui;
}

void Task::on_goReportBtn_clicked()
{
    Report* wgt = new Report(NULL);
    if (wgt->setup(myTask.report, 0, true))
    {
        views.push(wgt);
    }
    else delete wgt;
}
