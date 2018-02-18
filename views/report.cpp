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

Report::Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->commentsList);
    rp = new ReportPhotos(NULL);
    views.addObserver(this);
    ui->catalogSelector->setMaximumWidth(uiHelper.viewProperties().winWidth -10);
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

    for(int i=0; i<comments.size(); i++)
    {
        uiHelper.addWidgetToList(ui->commentsList,
                                 new ReportCommentsWidget(comments[i]));
    }

    Fesko::unreadComments()->flush();

    //Fake icon for increase combobox items height
    int cbih = uiHelper.viewProperties().winHeight/20;
    QPixmap pixmap(1, cbih);
    pixmap.fill(Qt::transparent);
    QIcon icon(pixmap);
    ui->catalogSelector->setIconSize(QSize(1, cbih));

    for (int ic =0; ic<report.catalogs.size(); ic++)//треба стак із моделєй
    {
        ui->catalogSelector->addItem(icon, report.catalogs[ic].catalogName);

    //версія 1-----------
//        CatalogPage* cwgt = new CatalogPage(ic,&report.catalogs[ic],
//                                            isReadOnly,
//                                            this);
//        connect(this, SIGNAL(needUpdate()), cwgt, SLOT(dataUpdate()));
//        ui->stack->addWidget(cwgt);        

/*        if (!ic)
            ui->stack->setCurrentWidget(cwgt);
*/
        //в рамках версії 2---------
        ShiftCatalogPage* shift = new ShiftCatalogPage;//відображення
        ModelCatalog* model = new ModelCatalog;//модель
        model->setCatalogIndex(ic);//сопутні данні
        listModels.append(model);//
        shift->setModel(model);//посилання на модель вілправляється до відображення
        ui->stack->addWidget(shift);//відображення монтується у стек
        if (!ic)
            ui->stack->setCurrentWidget(shift);
        //--------------------------

    }
    ui->stack->setCurrentIndex(0);
    if (isReadOnly)
    {
        ui->makePhotoBtn->setVisible(false);
        ui->makeReportBtn->setVisible(false);
    }
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

void Report::on_toolButton_2_clicked()
{
    views.pop();
}


void Report::on_makeReportBtn_clicked()
{    
    foreach (auto model, listModels) {//усі моделі вносять зміни до пакета відправки
        QVariantHash hash;
        hash = model->shortReportString();
        SingletonConnect::getInstance().appendReportDataShortToList(hash);
    }

    views.start_waiting();
    emit needUpdate();
    //check values
    for(int i=0; i<report.catalogs.size(); i++)
    {//що робить ця функція???
        int empty_cnt =0;
        int total_cnt = 0;
        for (int j=0; j<report.catalogs[i].reportItems.size(); j++)
        {//перебирається каталог
            for(int k=0; k<report.catalogs[i].reportItems[j].reportValues.size(); k++)
            {//перебирається ітем
                total_cnt++;//рахує загальну кількість проходів
                if (report.catalogs[i].reportItems[j].reportValues[k].value.trimmed().length())//якщо поле пусте сбрасується цикл
                    break;
                else
                    empty_cnt++;//якщо не пусте інкремент
            }
        }//for reportItems
        //if ((total_cnt == empty_cnt) && empty_cnt)hot point
        if(false)
        {
            QMessageBox msgBox;
            msgBox.setText("В каталозі має бути заповнено бодай одне поле");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            ui->catalogSelector->setCurrentIndex(i+1);
            views.stop_waiting();
            return;
        }
    }
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

void Report::on_catalogSelector_activated(int index)
{
    qDebug()<<index;
    ui->stack->setCurrentIndex(index);
}

void Report::on_addCommentBtn_clicked()
{
    Fesko::SComment comment;
    comment.text =ui->commentEdit->document()->toPlainText();
    if (!comment.text.length()) return;
    comment.time = QDateTime::currentDateTime();
    comment.reportID = report.id;

    Fesko::API.addComment(report.id, comment);
    Fesko::unreadComments()->markNewAsRead(comment);

    uiHelper.addWidgetToList(ui->commentsList, new ReportCommentsWidget(comment));
    ui->commentEdit->clear();
}
