#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QStackedWidget>
#include <QVector>

class ViewsObserver
{
public:
    virtual bool onViewPop(QWidget* current, bool isKey){Q_UNUSED(current);Q_UNUSED(isKey); return true;}

    virtual void onRestore(QWidget* lastWidget){Q_UNUSED(lastWidget);}
};

class ViewManager: public QObject
{
    Q_OBJECT

    explicit ViewManager(QObject *parent = 0);
public:
    static ViewManager& ref();

    void setViewStack(QStackedWidget* stack);
    void setDialogs(QStackedWidget* dlgsstackwgt,
                    QWidget *views,
                    QWidget *login,
                    QWidget *waiting,
                    QWidget *cam);

    void push(QWidget* widget, bool manage = false);
    void pop(bool isKey=false);

    void disablePop();
    void enablePop();

    void addObserver(ViewsObserver* o);
    void removeObserver(ViewsObserver* o);

    void start_waiting();
    void stop_waiting();

    void displayCamera();

    void backToViews();

    void logout();

    void error(int err_code);

private:
    QStackedWidget* stackWidget;
    QStackedWidget* dlgStackWidget;
    QWidget* viewsWgt;
    QWidget* loginWidget;
    QWidget* waitingWgt;
    QWidget* camWidget;

    QVector<ViewsObserver*> observers;

    bool isPopDisabled;
};

static ViewManager& views = ViewManager::ref();

class WAitingHelper
{
public:
    WAitingHelper()
    {
        views.start_waiting();
    }

    ~WAitingHelper()
    {
        views.stop_waiting();
    }
};

#define SHOW_WAITING_DIALOG WAitingHelper waitingDialogHelper;

#endif // VIEWMANAGER_H
