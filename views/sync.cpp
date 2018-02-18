#include "sync.h"
#include "ui_sync.h"

#include "backend/api.h"
#include "backend/sqldataprovider.h"
#include "backend/sitedataprovider.h"
#include "backend/fakedataprovider.h"
#include "backend/unreadcomments.h"

#include "viewmanager.h"

#include <QApplication>

const int DSYNC_PAST_DAYS = 2;
const int DSYNC_PRESENT_DAYS = 1;

Sync::Sync(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sync)
{
    ui->setupUi(this);

}

Sync::~Sync()
{
    delete ui;
}

int Sync::doSync()
{   
    Fesko::API.setDataProvider(Fesko::site_provider());
    int err = Fesko::API.login(Fesko::sql_provider()->lastLogin(),
                                Fesko::sql_provider()->lastPass());
    if (Fesko::NO_ERROR != err)
    {
        return err;

    }

    //Fesko::API.setDataProvider(Fesko::fake_provider());

    /*Fesko::TTasks ttt;
    err = Fesko::API.getTasks(ttt);
    return err;
    */

    err = upload();
    if (Fesko::NO_ERROR != err)
    {
        return err;

    }
    Fesko::API.setDataProvider(Fesko::site_provider());
    err = download();
    Fesko::API.setDataProvider(Fesko::sql_provider());
    return err;
}

int Sync::upload()
{
    QPixmap pix(":/pics/uploading.png");
    ui->syncImage->setPixmap(pix);
    ui->syncText->setText("Триває надсилання даних...");

    ui->currentProgress->setVisible(false);
    ui->commonLabel->setText("");
    ui->commonProgress->setValue(0);

    QApplication::processEvents();

    QVector<Fesko::SStoredRawData> raw;
    int err = Fesko::sql_provider()->rawData(raw);
    if (Fesko::NO_ERROR != err)
    {
        return err;
    }

    int size=0;
    for(int i=0; i<raw.size(); i++)
    {
        size+= raw[i].data.length();
    }
    ui->commonProgress->setMaximum(size);

    int progress=0;
    for (int i=0; i<raw.size(); i++)
    {
        ui->commonProgress->setValue(progress);
        QApplication::processEvents();

        err = Fesko::API.sendRaw(raw[i]);
        if (Fesko::NO_ERROR != err)
        {
            return err;
        }
        Fesko::sql_provider()->removeRawEntry(raw[i].id);
        progress+= raw[i].data.length();
    }


    return Fesko::NO_ERROR;
}

int Sync::download()
{
    QPixmap pix(":/pics/downloading.png");
    ui->syncImage->setPixmap(pix);
    ui->syncText->setText("Триває отримання даних...");

    QDate first = QDate::currentDate().addDays(0 - DSYNC_PAST_DAYS);
    QDate curr = first;
    QDate last = QDate::currentDate().addDays(DSYNC_PRESENT_DAYS);
    int SINGLE_PROGRESS_START = curr.daysTo(last);
    ui->commonProgress->setMaximum(SINGLE_PROGRESS_START+5);
    ui->currentProgress->setMaximum(100);
    ui->currentProgress->setVisible(true);

    const int REPORT_PERCENTAGE = 100;
    //const int OTHER_PERCENTAGE = 10;

    QApplication::processEvents();
    int day=0;


    Fesko::sql_provider()->beginSyncSession();
    Fesko::unreadComments()->beginAddComments();

    while (curr <= last)
    {
        ui->commonLabel->setText(tr("Маршрути на %1").arg(curr.toString()));
        ui->commonProgress->setValue(day++);

        ui->currentLabel->setText("Маршрути, звіти та коментарі");
        ui->currentProgress->setValue(0);
        QApplication::processEvents();
        Fesko::TRoutes routes;
        int err = Fesko::API.getRoutes(curr, routes);
        if ((/*Fesko::NO_ERROR != */err) && (Fesko::ERR_SRV_NO_DATA != err))
        {
            Fesko::sql_provider()->rollbackSyncSession();
            Fesko::API.setDataProvider(Fesko::sql_provider());
            return err;
        }

        float r_size = routes.size();
        for (int i=0; i<routes.size(); i++)
        {
            int progress_val = (int) 5 + (REPORT_PERCENTAGE - 5) * ((float) i / r_size) ;
            ui->currentProgress->setValue( progress_val );
            QApplication::processEvents();
            Fesko::TShopReports sr;
            err = Fesko::API.getShopReports(routes[i].date, routes[i].id, sr);
            if (/*Fesko::NO_ERROR != */err)
            {
                Fesko::sql_provider()->rollbackSyncSession();
                Fesko::API.setDataProvider(Fesko::sql_provider());
                return err;
            }
            for(int i=0; i<sr.size(); i++)
            {
                Fesko::SReport report;
                err = Fesko::API.getReport2(sr[i].id, report);
                if ((Fesko::NO_ERROR != err)&&(err != 8))
                {
                    Fesko::sql_provider()->rollbackSyncSession();
                    Fesko::API.setDataProvider(Fesko::sql_provider());
                    return err;
                }
                QVector<Fesko::SComment> comments;
                err = Fesko::API.getCommentByReportId(report.id, comments);
                if ((Fesko::NO_ERROR != err)&&(err != 8)&&(err !=5))
                {
                    Fesko::sql_provider()->rollbackSyncSession();
                    Fesko::API.setDataProvider(Fesko::sql_provider());
                    return err;
                }
                Fesko::unreadComments()->addComments(comments);
            }
        }
        QApplication::processEvents();

        curr = curr.addDays(1);
    }

    Fesko::unreadComments()->doneAddComments();

    ui->currentProgress->setVisible(false);
    ui->currentLabel->setVisible(false);

    ui->commonLabel->setText("Події");
    ui->commonProgress->setValue(SINGLE_PROGRESS_START + 1 );
    QApplication::processEvents();

    Fesko::TEvents events;
    int err = Fesko::API.getEvents(events, Fesko::etAll);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }
    err = Fesko::API.getEvents(events, Fesko::etTargetTask);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }
    err = Fesko::API.getEvents(events, Fesko::etAction);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }
    err = Fesko::API.getEvents(events, Fesko::etAdditioonalSpace);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }

    ui->commonLabel->setText("Всі коментарі");
    ui->commonProgress->setValue(SINGLE_PROGRESS_START + 2);
    QApplication::processEvents();
    QVector<Fesko::SCommentsListEntry> cms;
    err = Fesko::API.getComments(first, last, cms);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }

    ui->commonLabel->setText("Рекламації");
    ui->commonProgress->setValue(SINGLE_PROGRESS_START + 3);
    QApplication::processEvents();

    Fesko::SReclamations reclams;
    err = Fesko::API.getReclamList(reclams);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }

    ui->commonLabel->setText("Задачі");
    ui->commonProgress->setValue(SINGLE_PROGRESS_START + 4);
    QApplication::processEvents();

    Fesko::TTasks tasks;
    err = Fesko::API.getTasks(tasks);
    if (/*Fesko::NO_ERROR != */err)
    {
        Fesko::sql_provider()->rollbackSyncSession();
        Fesko::API.setDataProvider(Fesko::sql_provider());
        return err;
    }

    ui->commonLabel->setText("Досягнення");
    ui->commonProgress->setValue(SINGLE_PROGRESS_START + 5);
    QApplication::processEvents();

    Fesko::TArchivments archs;
    Fesko::API.getArchivments(archs);

    Fesko::sql_provider()->commitSyncSession();

    return /*Fesko::NO_ERROR*/0;
}
