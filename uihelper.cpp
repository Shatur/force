#include "uihelper.h"

#include <QScroller>

UIHelper::UIHelper(QObject *parent) : QObject(parent)
{
}

UIHelper &UIHelper::ref()
{
    static UIHelper* pMe = NULL;
    if (!pMe) pMe = new UIHelper(NULL);
    return *(pMe);
}

void UIHelper::setViewportWidth(int width)
{
    viewProps.winWidth = width;
}

void UIHelper::setViewportHeight(int height)
{
    viewProps.winHeight = height;
}

UIHelper::SViewportProperties UIHelper::viewProperties()
{
    return viewProps;
}

void UIHelper::setupListWidget(QListWidget *wgt)
{
    QScroller::grabGesture(wgt, QScroller::LeftMouseButtonGesture);
    wgt->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    wgt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    wgt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void UIHelper::addWidgetToList(QListWidget *list, QWidget* wgt)
{
    QListWidgetItem* item = new QListWidgetItem();
    wgt->setParent(list);
    list->addItem(item);
    list->setItemWidget(item, wgt);
    item->setSizeHint(wgt->sizeHint());
}
