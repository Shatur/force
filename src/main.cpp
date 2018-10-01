#include <QApplication>
#include <QFile>
#include <QApplication>
#include <QtDebug>
#include <QtGlobal>

#include "mainwindow.h"
#include "camera/cam_imgpreocessor.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
#if defined (Q_OS_ANDROID) || defined (Q_OS_IOS)
    w.showMaximized();
#else
    w.show();
#endif
    return a.exec();
}
