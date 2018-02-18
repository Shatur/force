#include "allcommentswidget.h"
#include "ui_allcommentswidget.h"

#include "views/report.h"
#include "uihelper.h"
#include "backend/unreadcomments.h"
#include "backend/sqldataprovider.h"

AllCommentsWidget::AllCommentsWidget(Fesko::SCommentsListEntry data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllCommentsWidget)
{
    ui->setupUi(this);

    reportWgt = 0;

    ui->reportLbl->setText(QString("Звіт № %1").arg(QString::number(data.report_id)));
    ui->textLbl->setText(data.lastText);

    Fesko::TReportComments comments;
    Fesko::API.getCommentByReportId(data.report_id, comments);
    Fesko::sql_provider()->mergeComments(data.report_id, comments);

    Fesko::SReportUnreadComments c_cnt = Fesko::unreadComments()->checkComments(comments);

    QString cnt = QString("%1/%2").arg(QString::number(c_cnt.allCount)).arg(QString::number(c_cnt.UnreadCount));
    ui->commentsCountLbl->setText(cnt);

    ui->textLbl->setMaximumWidth(uiHelper.viewProperties().winWidth);
    this->setMaximumWidth(uiHelper.viewProperties().winWidth);

    commentEntry = data;

    views.addObserver(this);
}

AllCommentsWidget::~AllCommentsWidget()
{
    delete ui;
    views.removeObserver(this);
}

bool AllCommentsWidget::onViewPop(QWidget *current, bool isKey)
{
    Q_UNUSED(isKey);
    if (reportWgt == current)
    {
        Fesko::TReportComments comments;
        Fesko::API.getCommentByReportId(commentEntry.report_id, comments);
        Fesko::sql_provider()->mergeComments(commentEntry.report_id, comments);

        Fesko::SReportUnreadComments c_cnt = Fesko::unreadComments()->checkComments(comments);

        QString cnt = QString("%1/%2").arg(QString::number(c_cnt.allCount)).arg(QString::number(c_cnt.UnreadCount));
        ui->commentsCountLbl->setText(cnt);
    }
    return true;
}

void AllCommentsWidget::on_goReportBtn_clicked()
{
    reportWgt = new Report();
    if (reportWgt->setup(commentEntry.report_id, 0, true))
    {
        views.push(reportWgt);
    }
    else
    {
        delete reportWgt;
        reportWgt = 0;
    }
}
