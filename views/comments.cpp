#include "comments.h"
#include "ui_comments.h"

#include "uihelper.h"
#include "backend/api.h"
#include "widgets/allcommentswidget.h"
#include "viewmanager.h"
#include "views/errordialog.h"
#include "views/report.h"

Comments::Comments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Comments)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->commentsList);
}

Comments::~Comments()
{
    delete ui;
}

bool Comments::setup()
{
    QVector<Fesko::SCommentsListEntry> comments;
    int err = Fesko::API.getComments(QDate::currentDate().addDays(-2),
                                     QDate::currentDate().addDays(1),
                                     comments);

    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }

    for (int i=0; i<comments.size(); i++)
    {
        uiHelper.addWidgetToList(ui->commentsList, new AllCommentsWidget(comments[i]));
    }

    return true;
}

void Comments::on_backButton_clicked()
{
    views.pop();
}
