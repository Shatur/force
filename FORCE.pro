#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T20:56:28
#
#-------------------------------------------------

QT       += sql core gui network positioning location multimedia quickwidgets sensors svg
#multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FORCE
TEMPLATE = app

#DEFINES += "SVN_REV=\"\\\"$$system(svnversion -n)\\\"\""

top_srcdir=$$PWD
ver_file = $$top_srcdir/version.h

#versionTarget.target = version.h
#versionTarget.depends = FORCE
#win32
#{
#versionTarget.commands = type NUL >> "$$ver_file"
#}
#!win32 {
#versionTarget.commands = touch "$$ver_file"
#}
#PRE_TARGETDEPS += version.h
#QMAKE_EXTRA_TARGETS += versionTarget

CONFIG += console c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    backend/api.cpp \
    widgets/pixmaplabel.cpp \
    widgets/routeitemwidget.cpp \
    backend/sitedataprovider.cpp \
    backend/dataprovider.cpp \
    backend/sqldataprovider.cpp \
    viewmanager.cpp \
    views/mainmenu.cpp \
    views/showroute.cpp \
    views/selectbrand.cpp \
    views/events.cpp \
    widgets/eventitemwidget.cpp \
    gps.cpp \
    views/report.cpp \
    uihelper.cpp \
    views/errordialog.cpp \
    views/reportphotos.cpp \
    widgets/reportphotowidget.cpp \
    camera/cam_imgpreocessor.cpp \
    widgets/qmlcamwidget.cpp \
    widgets/report/catalogpage.cpp \
    widgets/report/reportitem.cpp \
    widgets/report/cataloglistitem.cpp \
    widgets/report/cataloglegend.cpp \
    views/reclamations.cpp \
    widgets/reclamation.cpp \
    views/sync.cpp \
    backend/jsondata.cpp \
    backend/fakedataprovider.cpp \
    widgets/allcommentswidget.cpp \
    views/comments.cpp \
    widgets/report/reportcommentswidget.cpp \
    views/tasks.cpp \
    widgets/task.cpp \
    backend/unreadcomments.cpp \
    views/archivments.cpp \
    widgets/archivment.cpp \
    views/settings.cpp \
    backend/singletonconnect.cpp \
    widgets/report/shiftcatalogpage.cpp \
    mvc/catalog.cpp \
    mvc/comment.cpp \
    backend/fileside.cpp

HEADERS  += mainwindow.h \
    backend/api.h \
    common.h \
    widgets/pixmaplabel.h \
    widgets/routeitemwidget.h \
    backend/dataprovider.h \
    backend/sitedataprovider.h \
    backend/datacache.h \
    backend/datatypes.h \
    backend/sqldataprovider.h \
    viewmanager.h \
    views/mainmenu.h \
    views/showroute.h \
    views/selectbrand.h \
    views/events.h \
    widgets/eventitemwidget.h \
    gps.h \
    views/report.h \
    uihelper.h \
    views/errordialog.h \
    views/reportphotos.h \
    widgets/reportphotowidget.h \
    camera/cam_imgpreocessor.h \
    widgets/qmlcamwidget.h \
    widgets/report/catalogpage.h \
    widgets/report/reportitem.h \
    widgets/report/cataloglistitem.h \
    widgets/report/cataloglegend.h \
    views/reclamations.h \
    widgets/reclamation.h \
    views/sync.h \
    backend/jsondata.h \
    backend/fakedataprovider.h \
    $$ver_file \
    widgets/allcommentswidget.h \
    views/comments.h \
    widgets/report/reportcommentswidget.h \
    app_features.h \
    views/tasks.h \
    widgets/task.h \
    backend/unreadcomments.h \
    views/archivments.h \
    widgets/archivment.h \
    views/settings.h \
    backend/singletonconnect.h \
    widgets/report/shiftcatalogpage.h \
    mvc/catalog.h \
    mvc/comment.h \
    backend/fileside.h

FORMS    += mainwindow.ui \
    widgets/routeitemwidget.ui \
    views/mainmenu.ui \
    views/showroute.ui \
    views/selectbrand.ui \
    views/events.ui \
    widgets/eventitemwidget.ui \
    views/report.ui \
    views/errordialog.ui \
    views/reportphotos.ui \
    widgets/reportphotowidget.ui \
    widgets/qmlcamwidget.ui \
    widgets/report/catalogpage.ui \
    widgets/report/reportitem.ui \
    widgets/report/cataloglistitem.ui \
    widgets/report/cataloglegend.ui \
    views/reclamations.ui \
    widgets/reclamation.ui \
    views/sync.ui \
    widgets/allcommentswidget.ui \
    views/comments.ui \
    widgets/report/reportcommentswidget.ui \
    views/tasks.ui \
    widgets/task.ui \
    views/archivments.ui \
    widgets/archivment.ui \
    views/settings.ui \
    widgets/report/shiftcatalogpage.ui

RESOURCES += \
    appres.qrc


DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    backend/createdb.sql \
    camera/qmlcamera.qml \
    pics/view_report.png \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    ui/qml/test.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
