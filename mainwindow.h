#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "backend/api.h"
#include "views/mainmenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void doLogin(QWidget* nextWidget = 0, QString message = QString());
    virtual void resizeEvent(QResizeEvent *event);

    int performLogin();

private slots:
    void on_loginBtn_clicked();

    void on_routesBtn_clicked();

    void on_eventsBtn_clicked();

    void on_mainStack_currentChanged(int arg1);

private:
    Ui::MainWindow *ui;

    MainMenu* mainMenu;

    int doDataSync();

protected:
    virtual void keyReleaseEvent(QKeyEvent* e);
    virtual void keyPressEvent(QKeyEvent *e);
    //Fresko::FreskoAPI api;
};

#endif // MAINWINDOW_H
