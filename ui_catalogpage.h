/********************************************************************************
** Form generated from reading UI file 'catalogpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGPAGE_H
#define UI_CATALOGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <widgets/report/cataloglegend.h>

QT_BEGIN_NAMESPACE

class Ui_CatalogPage
{
public:
    QVBoxLayout *verticalLayout;
    CatalogLegend *legend;
    QListWidget *itemsList;

    void setupUi(QWidget *CatalogPage)
    {
        if (CatalogPage->objectName().isEmpty())
            CatalogPage->setObjectName(QStringLiteral("CatalogPage"));
        CatalogPage->resize(265, 300);
        verticalLayout = new QVBoxLayout(CatalogPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        legend = new CatalogLegend(CatalogPage);
        legend->setObjectName(QStringLiteral("legend"));

        verticalLayout->addWidget(legend);

        itemsList = new QListWidget(CatalogPage);
        itemsList->setObjectName(QStringLiteral("itemsList"));

        verticalLayout->addWidget(itemsList);


        retranslateUi(CatalogPage);

        QMetaObject::connectSlotsByName(CatalogPage);
    } // setupUi

    void retranslateUi(QWidget *CatalogPage)
    {
        CatalogPage->setWindowTitle(QApplication::translate("CatalogPage", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CatalogPage: public Ui_CatalogPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGPAGE_H
