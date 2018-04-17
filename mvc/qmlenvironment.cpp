#include "qmlenvironment.h"
#include <QApplication>
QmlEnvironment::QmlEnvironment(QObject *parent) : QObject(parent)
{
    shiftWindow = new QQuickView;
    shiftWindow->setResizeMode(QQuickView::SizeRootObjectToView);
    shiftWindow->setSource(QUrl("qrc:/ui/qml/test.qml"));
    shiftWindow->show();

}

void QmlEnvironment::shift()
{

        QApplication::allWindows().first()->setFlag(Qt::WindowStaysOnTopHint);
//    shiftStatus = !shiftStatus;
//    if(shiftStatus)
//        QApplication::allWindows().first()->setFlag(Qt::WindowStaysOnTopHint);
//    else
//        QApplication::allWindows().last()->setFlag(Qt::WindowStaysOnTopHint);
}
