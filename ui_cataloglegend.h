/********************************************************************************
** Form generated from reading UI file 'cataloglegend.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGLEGEND_H
#define UI_CATALOGLEGEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatalogLegend
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *staticItemsLayout;
    QVBoxLayout *dynamicItemsLayout;

    void setupUi(QWidget *CatalogLegend)
    {
        if (CatalogLegend->objectName().isEmpty())
            CatalogLegend->setObjectName(QStringLiteral("CatalogLegend"));
        CatalogLegend->resize(318, 70);
        CatalogLegend->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(CatalogLegend);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        staticItemsLayout = new QVBoxLayout();
        staticItemsLayout->setObjectName(QStringLiteral("staticItemsLayout"));

        horizontalLayout->addLayout(staticItemsLayout);

        dynamicItemsLayout = new QVBoxLayout();
        dynamicItemsLayout->setObjectName(QStringLiteral("dynamicItemsLayout"));

        horizontalLayout->addLayout(dynamicItemsLayout);


        retranslateUi(CatalogLegend);

        QMetaObject::connectSlotsByName(CatalogLegend);
    } // setupUi

    void retranslateUi(QWidget *CatalogLegend)
    {
        CatalogLegend->setWindowTitle(QApplication::translate("CatalogLegend", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CatalogLegend: public Ui_CatalogLegend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGLEGEND_H
