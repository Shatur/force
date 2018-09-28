#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "backend/api.h"
#include "viewmanager.h"
namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget, public ViewsObserver
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

    void setCaption(QString txt);
    void setup();

     virtual void onRestore(QWidget* lastWidget);

private slots:
    void on_routesBtn_clicked();

    void on_eventsBtn_clicked();

    void on_exitBtn_clicked();

    void on_reclamationBtn_clicked();

    void on_syncButton_clicked();

    void on_commentsBtn_clicked();

    void on_tasksBtn_clicked();

    void on_archivmentsBtn_clicked();

    void on_settingsBtn_clicked();

private:
    void calculateReclamations();

    Ui::MainMenu *ui;

    Fesko::SReclamations reclams;
    bool isReclamationsView;
};

#endif // MAINMENU_H
