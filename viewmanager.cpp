#include "viewmanager.h"

#include <QApplication>

ViewManager::ViewManager(QObject *parent): QObject(parent)
{    
    isPopDisabled = false;
}

ViewManager &ViewManager::ref()
{
    static ViewManager* pMe;
    if (!pMe)
    {
        pMe = new ViewManager;
    }

    return *(pMe);
}

void ViewManager::setDialogs(QStackedWidget *dlgsstackwgt, QWidget* views, QWidget *login, QWidget* waiting, QWidget *cam)
{
    dlgStackWidget = dlgsstackwgt;
    viewsWgt = views;
    loginWidget = login;
    waitingWgt = waiting;
    camWidget = cam;
}

void ViewManager::setViewStack(QStackedWidget *stack)
{
    stackWidget = stack;//головний стек віджетів
}

void ViewManager::push(QWidget *widget, bool manage)
{
    if (!stackWidget) return;
    if (manage) widget->setParent(stackWidget);
    stackWidget->addWidget(widget);
    stackWidget->setCurrentWidget(widget);
}

void ViewManager::pop(bool isKey)
{
    if (isPopDisabled) return;
    if (!stackWidget) return;
    int idx = stackWidget->currentIndex();
    if (idx<2) return;
    QWidget* wgt = stackWidget->currentWidget();

    for(int i=0; i<observers.size();i++)
    {
        if (observers[i])
        {
            if (!observers[i]->onViewPop(wgt, isKey))
                return;
        }
    }

    stackWidget->setCurrentIndex(idx-1);
    stackWidget->removeWidget(wgt);
    QWidget* new_wgt;
    //wgt->deleteLater();
    new_wgt = stackWidget->currentWidget();
    new_wgt->setEnabled(true);

    for(int i=0; i<observers.size();i++)
    {
        if (observers[i])
            if (observers[i] == (ViewsObserver*)new_wgt)
            {
                if (!observers[i]->onViewPop(wgt, isKey))
                    return;
            }
    }//for all observers
}

void ViewManager::disablePop()
{
    isPopDisabled = true;
}

void ViewManager::enablePop()
{
    isPopDisabled = false;
}

void ViewManager::addObserver(ViewsObserver *o)
{
    for(int i=0; i<observers.size(); i++)
    {
        if (observers[i] == o)
            return;
    }
    observers.push_back(o);
}

void ViewManager::removeObserver(ViewsObserver *o)
{
    QVector<ViewsObserver*>::iterator it = observers.begin();
    while(it != observers.end())
    {
        if ((*it) == o)
        {
            it = observers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void ViewManager::start_waiting()
{
    stackWidget->currentWidget()->setEnabled(false);

    QApplication::processEvents();

    if (!dlgStackWidget) return;

    if (waitingWgt)
        dlgStackWidget->setCurrentWidget(waitingWgt);
}

void ViewManager::stop_waiting()
{
    stackWidget->currentWidget()->setEnabled(true);
    if (!dlgStackWidget) return;

    if (viewsWgt)
        dlgStackWidget->setCurrentWidget(viewsWgt);
}

void ViewManager::displayCamera()
{
    if (camWidget && dlgStackWidget)
        dlgStackWidget->setCurrentWidget(camWidget);
}

void ViewManager::backToViews()
{
    if (viewsWgt && dlgStackWidget)
        dlgStackWidget->setCurrentWidget(viewsWgt);
}

void ViewManager::logout()
{
    dlgStackWidget->setCurrentWidget(loginWidget);
}
