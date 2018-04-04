#include "report.h"
#include "ui_report.h"

#include "backend/api.h"
#include "backend/sqldataprovider.h"
#include "backend/unreadcomments.h"

#include "widgets/report/cataloglistitem.h"
#include "widgets/report/reportitem.h"
#include "widgets/report/catalogpage.h"
#include "widgets/report/shiftcatalogpage.h"
#include "views/errordialog.h"
#include "widgets/report/reportcommentswidget.h"
//#include "views/cameraview.h"

#include "viewmanager.h"
#include "uihelper.h"

#include <QScroller>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include <QQuickView>
#include <QQmlContext>

Report::Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);

    rp = new ReportPhotos(NULL);
    views.addObserver(this);
    is_done = false;
}

Report::~Report()
{
    views.removeObserver(this);
    delete ui;
}

bool Report::setup(int report_id, int shop_id, bool isReadOnly)
{
    id = report_id;
    sid = shop_id;
    read_only = isReadOnly;    
    SHOW_WAITING_DIALOG;

    int err = Fesko::API.getReport2(id, report);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }    

    bool is_dirty= Fesko::sql_provider()->mergeReport(report);       

    Fesko::TReportComments comments;
    err = Fesko::API.getCommentByReportId(id, comments);
    if (Fesko::NO_ERROR != err)
    {
        SHOW_ERROR_DIALOG(err);
        return false;
    }
    Fesko::sql_provider()->mergeComments(report.id, comments);

    commentModel = new Comment;
    commentModel->setReportId(id);
    for(int i=0; i<comments.size(); i++)
    {
        commentModel->setComment(comments[i].time,
                                 comments[i].text,
                                 comments[i].isUnread);
        //uiHelper.addWidgetToList(ui->commentsList, new ReportCommentsWidget(comments[i]));
    }

    Fesko::unreadComments()->flush();





   catalogModel = new Catalog;
   catalogModel->setReadOnlyFlag(read_only);//надалі согласовувати із сінглтоном

//   QQuickView* view = new QQuickView;
//   view->rootContext()->setContextProperty("Catalog", catalogModel);
//   view->setSource(QUrl("qrc:/ui/qml/Catalog/CatalogView.qml"));
//   view->show();


   //QQuickView *view = new QQuickView();
   //QWidget *container = QWidget::createWindowContainer(view);
   //container->setMinimumSize(200, 200);
   //container->setMaximumSize(500, 500);

//   view->setSource(QUrl("qrc:/ui/qml/test.qml"));
//   view->setResizeMode(QQuickView::SizeRootObjectToView);
//    view->show();
//    view->hide();
//    view->show();

    ShiftCatalogPage* _shift = new ShiftCatalogPage;
    _shift->setCatalog(catalogModel);
    _shift->setComment(commentModel);
    ui->verticalLayout->addWidget(_shift);
    //ui->stack->setCurrentIndex(1);

    connect(_shift,&ShiftCatalogPage::destroyed,[=]{
        catalogModel->deleteLater();
        commentModel->deleteLater();
    });
    connect(_shift,&ShiftCatalogPage::toComment,commentModel,&Comment::reciverSlot);
    connect(_shift,&ShiftCatalogPage::toAction,[=](QString a){
        if(a.contains("back"))
            on_stepBack_clicked();
        if(a.contains("photo"))
            on_makePhotoBtn_clicked();
        if(a.contains("push"))
            on_makeReportBtn_clicked();
        qDebug()<<a;
    });
    return true;
}

bool Report::onViewPop(QWidget *current, bool isKey)
{
    Q_UNUSED(isKey);

    if (is_done) return true;

    if (current!=this) return true;

    if (read_only) return true;

    return QMessageBox::Yes == QMessageBox::question(this, "Вихід", "Вийти зі звіту без збереження?",
                                                    QMessageBox::Yes|QMessageBox::No);
}

void Report::on_stepBack_clicked()//back button
{
    views.pop();
    this->deleteLater();
}


void Report::on_makeReportBtn_clicked()
{
    views.start_waiting();

    if(!catalogModel->goodJobFinish()){
        QMessageBox msgBox;
        msgBox.setText("В каталозі має бути заповнено бодай одне поле");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        views.stop_waiting();
        return;
    }

    QVariantHash hash;//хеш бо вдобно ввіддати у сусідній клас
    hash = catalogModel->shortReportString();
    SingletonConnect::getInstance().appendReportDataShortToList(hash);

// до бази
    Fesko::API.setReport(report);

    QVector<SPhotoInfo> photos;
    rp->getPhotos(photos);

    for(int i=0; i<photos.size(); i++)
    {
        Fesko::API.setReportPhoto(id, photos[i].datetime, sid, photos[i].photo);
    }

    views.stop_waiting();

    is_done = true;

    views.pop();
}

void Report::on_makePhotoBtn_clicked()
{
    /*CameraView* wgt = new CameraView(this);
    views.push(wgt);*/
    views.push(rp, false);
}

void Report::on_addCommentBtn_clicked()
{
//    Fesko::SComment comment;
//    comment.text = ui->commentEdit->document()->toPlainText();
//    if (!comment.text.length()) return;
//    comment.time = QDateTime::currentDateTime();
//    comment.reportID = report.id;

//    Fesko::API.addComment(report.id, comment);
//    Fesko::unreadComments()->markNewAsRead(comment);
}
