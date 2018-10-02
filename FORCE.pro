#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T20:56:28
#
#-------------------------------------------------

QT += core gui network sql positioning location multimedia quickwidgets sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FORCE
TEMPLATE = app
CONFIG += console c++11
INCLUDEPATH += $$PWD/src

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/backend/api.cpp \
    src/widgets/pixmaplabel.cpp \
    src/widgets/routeitemwidget.cpp \
    src/backend/sitedataprovider.cpp \
    src/backend/dataprovider.cpp \
    src/backend/sqldataprovider.cpp \
    src/viewmanager.cpp \
    src/views/mainmenu.cpp \
    src/views/showroute.cpp \
    src/views/selectbrand.cpp \
    src/views/events.cpp \
    src/widgets/eventitemwidget.cpp \
    src/gps.cpp \
    src/views/report.cpp \
    src/uihelper.cpp \
    src/views/errordialog.cpp \
    src/views/reportphotos.cpp \
    src/widgets/reportphotowidget.cpp \
    src/camera/cam_imgpreocessor.cpp \
    src/widgets/qmlcamwidget.cpp \
    src/widgets/report/catalogpage.cpp \
    src/widgets/report/reportitem.cpp \
    src/widgets/report/cataloglistitem.cpp \
    src/widgets/report/cataloglegend.cpp \
    src/views/reclamations.cpp \
    src/widgets/reclamation.cpp \
    src/views/sync.cpp \
    src/backend/jsondata.cpp \
    src/backend/fakedataprovider.cpp \
    src/widgets/allcommentswidget.cpp \
    src/views/comments.cpp \
    src/widgets/report/reportcommentswidget.cpp \
    src/views/tasks.cpp \
    src/widgets/task.cpp \
    src/backend/unreadcomments.cpp \
    src/views/archivments.cpp \
    src/widgets/archivment.cpp \
    src/views/settings.cpp \
    src/mvc/modelcatalog.cpp \
    src/backend/singletonconnect.cpp \
    src/widgets/report/shiftcatalogpage.cpp

HEADERS += \
    src/mainwindow.h \
    src/version.h \
    src/backend/api.h \
    src/common.h \
    src/widgets/pixmaplabel.h \
    src/widgets/routeitemwidget.h \
    src/backend/dataprovider.h \
    src/backend/sitedataprovider.h \
    src/backend/datacache.h \
    src/backend/datatypes.h \
    src/backend/sqldataprovider.h \
    src/viewmanager.h \
    src/views/mainmenu.h \
    src/views/showroute.h \
    src/views/selectbrand.h \
    src/views/events.h \
    src/widgets/eventitemwidget.h \
    src/gps.h \
    src/views/report.h \
    src/uihelper.h \
    src/views/errordialog.h \
    src/views/reportphotos.h \
    src/widgets/reportphotowidget.h \
    src/camera/cam_imgpreocessor.h \
    src/widgets/qmlcamwidget.h \
    src/widgets/report/catalogpage.h \
    src/widgets/report/reportitem.h \
    src/widgets/report/cataloglistitem.h \
    src/widgets/report/cataloglegend.h \
    src/views/reclamations.h \
    src/widgets/reclamation.h \
    src/views/sync.h \
    src/backend/jsondata.h \
    src/backend/fakedataprovider.h \
    src/widgets/allcommentswidget.h \
    src/views/comments.h \
    src/widgets/report/reportcommentswidget.h \
    src/app_features.h \
    src/views/tasks.h \
    src/widgets/task.h \
    src/backend/unreadcomments.h \
    src/views/archivments.h \
    src/widgets/archivment.h \
    src/views/settings.h \
    src/mvc/modelcatalog.h \
    src/backend/singletonconnect.h \
    src/widgets/report/shiftcatalogpage.h

FORMS += \
    src/mainwindow.ui \
    src/widgets/routeitemwidget.ui \
    src/views/mainmenu.ui \
    src/views/showroute.ui \
    src/views/selectbrand.ui \
    src/views/events.ui \
    src/widgets/eventitemwidget.ui \
    src/views/report.ui \
    src/views/errordialog.ui \
    src/views/reportphotos.ui \
    src/widgets/reportphotowidget.ui \
    src/widgets/qmlcamwidget.ui \
    src/widgets/report/catalogpage.ui \
    src/widgets/report/reportitem.ui \
    src/widgets/report/cataloglistitem.ui \
    src/widgets/report/cataloglegend.ui \
    src/views/reclamations.ui \
    src/widgets/reclamation.ui \
    src/views/sync.ui \
    src/widgets/allcommentswidget.ui \
    src/views/comments.ui \
    src/widgets/report/reportcommentswidget.ui \
    src/views/tasks.ui \
    src/widgets/task.ui \
    src/views/archivments.ui \
    src/widgets/archivment.ui \
    src/views/settings.ui \
    src/widgets/report/shiftcatalogpage.ui

RESOURCES += \
    resources.qrc

OTHER_FILES = \
    qml/qmlcamera.qml \
    qml/Catalog/CatalogView.qml \
    qml/Catalog/Delegate.qml \
    qml/Catalog/Header.qml \
    qml/components/DoubleEdit.qml \
    qml/components/PressBox.qml \
    qml/components/SettingPanel.qml \

DISTFILES += \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
