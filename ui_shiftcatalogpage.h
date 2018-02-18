/********************************************************************************
** Form generated from reading UI file 'shiftcatalogpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIFTCATALOGPAGE_H
#define UI_SHIFTCATALOGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_ShiftCatalogPage
{
public:
    QVBoxLayout *verticalLayout;
    QQuickWidget *quickWidget;

    void setupUi(QWidget *ShiftCatalogPage)
    {
        if (ShiftCatalogPage->objectName().isEmpty())
            ShiftCatalogPage->setObjectName(QStringLiteral("ShiftCatalogPage"));
        //ShiftCatalogPage->resize(265, 300);

        verticalLayout = new QVBoxLayout(ShiftCatalogPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        quickWidget = new QQuickWidget(ShiftCatalogPage);
        quickWidget->setObjectName(QStringLiteral("quickWidget"));

        verticalLayout->addWidget(quickWidget);
        retranslateUi(ShiftCatalogPage);

        QMetaObject::connectSlotsByName(ShiftCatalogPage);
    } // setupUi

    void retranslateUi(QWidget *ShiftCatalogPage)
    {
        ShiftCatalogPage->setWindowTitle(QApplication::translate("ShiftCatalogPage", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShiftCatalogPage: public Ui_ShiftCatalogPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIFTCATALOGPAGE_H
