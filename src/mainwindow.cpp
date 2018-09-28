#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/routeitemwidget.h"

#include "backend/sitedataprovider.h"
#include "backend/sqldataprovider.h"
#include "backend/unreadcomments.h"

#include "views/sync.h"

#include "viewmanager.h"

#include "version.h"

#include "gps.h"
#include "uihelper.h"
#include "camera/cam_imgpreocessor.h"

#include <QPixmap>
#include <QScroller>
#include <QScrollBar>
#include <QKeyEvent>
#include <QMessageBox>
#include <QScreen>

#include "backend/datatypes.h"

const int DSYNC_PAST_DAYS = 2;
const int DSYNC_PRESENT_DAYS = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"main size"<<this->size();

#if defined (Q_OS_ANDROID) || defined (Q_OS_IOS)
    QScreen *screen = QApplication::screens().at(0);
    QSize screen_size = screen->availableSize();

    QRect geometry = this->geometry();
    geometry.setSize(screen_size);
    this->setGeometry(geometry);

    this->setMaximumSize(screen_size);
#endif

    qmlRegisterType<CamImageProcessor>("ImageProcessor", 1, 0, "ImageProcessor");

    //ui->mainStack->setCurrentWidget(ui->loginPage);
    Fesko::API.setDataProvider(Fesko::site_provider());
    doLogin(NULL);

    mainMenu = new MainMenu;
    views.setViewStack(ui->viewsStack);
    views.setDialogs(ui->mainStack, ui->viewsPage, ui->loginPage, ui->waitingPage, ui->photoPage);
    views.push(mainMenu);

    Fesko::API.setCache(Fesko::sql_provider());

    gps::ref();

    trial_exit();

    ui->qmlcam->setSource(QUrl("qrc:/qml/qmlcamera.qml"));
    QQuickItem* qmlRoot = ui->qmlcam->rootObject();
    connect(qmlRoot, SIGNAL(donePhoto(QString, int)), CameraImage(), SLOT(emitImage(QString, int)));

    ui->versionLabel->setText(versionFull());

    Fesko::unreadComments()->read();

#ifdef DEFAULT_LOGIN
    ui->loginLE->setText(DEFAULT_LOGIN);
#endif
#ifdef DEFAULT_PASSWORD
    ui->passwordLE->setText(DEFAULT_PASSWORD);
#endif

    on_mainStack_currentChanged(0);

    ui->loginLE->setText(Fesko::sql_provider()->lastLogin());
    ui->passwordLE->setText(Fesko::sql_provider()->lastPass());

#ifdef SHOW_CAM_AT_STARTUP
   ui->mainStack->setCurrentWidget(ui->photoPage);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doLogin(QWidget *nextWidget, QString message)
{
    ui->mainStack->setCurrentWidget(ui->loginPage);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    uiHelper.setViewportWidth(this->size().width());
}

int MainWindow::performLogin()
{
    trial_exit();
    int err = Fesko::API.login(ui->loginLE->text(), ui->passwordLE->text());
    if (/*Fesko::NO_ERROR != */err)
    {
        ui->loginErrorLabel->setText(Fesko::errorToString(err));
    }
    else
    {
        mainMenu->setCaption(ui->loginLE->text());
    }

    return err;
}

void MainWindow::on_loginBtn_clicked()
{
    QDate lastLogin;
    QDate lastSync;

    ui->loginBtn->setEnabled(false);

    bool isSiteLogin = false;
    bool isDataSync = false;

    int err = Fesko::sql_provider()->lastLoginDate(lastLogin);
    isSiteLogin = (QDate::currentDate() != lastLogin) || (/*Fesko::NO_ERROR != */err);
    err = Fesko::sql_provider()->lastSyncDate(lastSync);
    isDataSync = (QDate::currentDate() != lastSync) || (/*Fesko::NO_ERROR != */err);

    /*Fesko::API.setDataProvider((isSiteLogin)? Fesko::site_provider()
                                             :Fesko::sql_provider());*/

#ifndef DISABLE_CACHE
    if (isSiteLogin || isDataSync) Fesko::API.setDataProvider( Fesko::site_provider() );
            else Fesko::API.setDataProvider( Fesko::sql_provider() );
#else
    Fesko::API.setDataProvider( Fesko::site_provider() );
#endif

    err = performLogin();
    if (/*Fesko::NO_ERROR != */err)
    {
        if ((Fesko::ERR_BAD_LOGIN) && (!isSiteLogin))
        {
            // If we cant login using cache probaly we trying to login as different user
            // In this case use site auth
            Fesko::API.setDataProvider(Fesko::site_provider());
            err= performLogin();
            if (/*Fesko::NO_ERROR != */!err)
            {
                // Ok. We logged in as different user. Re-read cache
                isDataSync = true;
                Fesko::sql_provider()->clearResponces();
                Fesko::unreadComments()->clear();
            }
            else
            {
                ui->loginBtn->setEnabled(true);
                return;
            }
        }
        else
        {
            ui->loginBtn->setEnabled(true);
            return;
        }
    }

#ifndef DISABLE_CACHE
    if (isDataSync)
    {
        err = doDataSync();
        if (/*Fesko::NO_ERROR != */err)
        {
            ui->loginErrorLabel->setText(Fesko::errorToString(err));
            ui->mainStack->setCurrentWidget(ui->loginPage);
            ui->loginBtn->setEnabled(true);
            return;
        }
    }
    Fesko::API.setDataProvider(Fesko::sql_provider());
#else
    Fesko::API.setDataProvider(Fesko::site_provider());
#endif
    mainMenu->setup();
    ui->mainStack->setCurrentWidget(ui->viewsPage);
    ui->loginBtn->setEnabled(true);
}

void MainWindow::on_routesBtn_clicked()
{
    Fesko::TRoutes routes;

    if (/*Fesko::NO_ERROR != */Fesko::API.getRoutes(QDate::currentDate().addDays(3), routes))
    {
        return;
    }

}

void MainWindow::on_eventsBtn_clicked()
{
    Fesko::TEvents events;
    //Fesko::API.getEvents(events);

}


int MainWindow::doDataSync()
{
    ui->mainStack->setCurrentWidget(ui->viewsPage);

    Sync* sync = new Sync(this);

    views.push(sync);

    views.disablePop();

    int err = sync->doSync();

    views.enablePop();

    views.pop();

    ui->mainStack->setCurrentWidget(ui->loginPage);

    return err;
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if ((e->key () == Qt::Key_Back) || (e->key() == Qt::Key_Escape))
    {
        if (ui->mainStack->currentWidget() == ui->viewsPage)
        {
            views.pop(true);
            e->accept ();
        }
        else if (ui->mainStack->currentWidget() == ui->photoPage)
        {
            ui->mainStack->setCurrentWidget(ui->viewsPage);
        }
        else if (ui->mainStack->currentWidget() == ui->loginPage)
        {
            if (QMessageBox::Yes == QMessageBox::question(this, "Вихід", "Вийти з додатку?",
                                                          QMessageBox::Yes|QMessageBox::No))
            {
                this->close();
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (ui->mainStack->currentWidget() != ui->loginPage)
    {
        QWidget::keyPressEvent (e);
        return;
    }
    switch (e->key ()) {
        case Qt::Key_Return:
        case Qt::Key_Enter:
            focusNextPrevChild (true);
            break;

        default:
            QWidget::keyPressEvent (e);
        }
}

void MainWindow::on_mainStack_currentChanged(int arg1)
{
    int cam_index=4;
    static int old_index = cam_index;
    for(int i=0; i<ui->mainStack->count();i++)
    {
        if (ui->photoPage == ui->mainStack->widget(i))
        {
            cam_index = i;
            break;
        }
    }

    if ((old_index == cam_index) || (arg1 == cam_index))
    {
        QObject* qmlroot = ui->qmlcam->rootObject();
        if (!qmlroot)
        {
            qDebug()<<"BAD QML root!";
            return;
        }

        QVariant returnedValue;

        if(cam_index == old_index)
        {
            qDebug()<<"camHide calls...";
            QMetaObject::invokeMethod(qmlroot, "camHide",
                            Q_RETURN_ARG(QVariant, returnedValue));
        }
        else
        {
            qDebug()<<"camShow calls...";
            QMetaObject::invokeMethod(qmlroot, "camShow",
                            Q_RETURN_ARG(QVariant, returnedValue));
        }

    }
    qDebug()<<"old:"<<old_index;
    qDebug()<<"new:"<<arg1;
    old_index = arg1;
}
