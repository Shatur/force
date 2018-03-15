/********************************************************************************
** Form generated from reading UI file 'qmlcamwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMLCAMWIDGET_H
#define UI_QMLCAMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_QMLCamWidget
{
public:
    QQuickWidget *qmlcam;

    void setupUi(QWidget *QMLCamWidget)
    {
        if (QMLCamWidget->objectName().isEmpty())
            QMLCamWidget->setObjectName(QStringLiteral("QMLCamWidget"));
        QMLCamWidget->resize(290, 300);
        qmlcam = new QQuickWidget(QMLCamWidget);
        qmlcam->setObjectName(QStringLiteral("qmlcam"));
        qmlcam->setGeometry(QRect(108, 60, 251, 201));
        qmlcam->setResizeMode(QQuickWidget::SizeRootObjectToView);

        retranslateUi(QMLCamWidget);

        QMetaObject::connectSlotsByName(QMLCamWidget);
    } // setupUi

    void retranslateUi(QWidget *QMLCamWidget)
    {
        QMLCamWidget->setWindowTitle(QApplication::translate("QMLCamWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QMLCamWidget: public Ui_QMLCamWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMLCAMWIDGET_H
