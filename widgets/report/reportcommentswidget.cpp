#include "reportcommentswidget.h"
#include "ui_reportcommentswidget.h"

#include "uihelper.h"

#include <QFont>
#include <backend/unreadcomments.h>

ReportCommentsWidget::ReportCommentsWidget(Fesko::SComment comment, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportCommentsWidget)
{
    ui->setupUi(this);
    ui->borderGb->setTitle(comment.time.toString("dd.MM.yyyy hh:mm"));
    ui->text->setText(comment.text);
    Fesko::unreadComments()->checkComment(comment);
    QFont font = ui->text->font();
    font.setBold(comment.isUnread);
    ui->text->setFont(font);

    ui->borderGb->setMaximumWidth(uiHelper.viewProperties().winWidth);
    ui->text->setMaximumWidth(uiHelper.viewProperties().winWidth);
    this->setMaximumWidth(uiHelper.viewProperties().winWidth);

    Fesko::unreadComments()->markAsRead(comment);
}

ReportCommentsWidget::~ReportCommentsWidget()
{
    delete ui;
}
