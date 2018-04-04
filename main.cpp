#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QApplication>
#include <QtDebug>
#include <QtGlobal>
#include "backend/fileside.h"

#include "camera/cam_imgpreocessor.h"


#ifdef Q_OS_WIN32

static QFile dbg("d:\\fesko_debug.txt");

void myMessageOutput(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    dbg.write(str.toStdString().c_str());
}

#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileSide fileSide;
    MainWindow w;

#ifdef Q_OS_WIN32
    dbg.open(QIODevice::Truncate | QIODevice::WriteOnly);
    //qInstallMessageHandler(myMessageOutput);

#endif
#if defined (Q_OS_ANDROID) || defined (Q_OS_IOS)
    w.showMaximized();
#else
    w.show();
#endif
    return a.exec();
}
