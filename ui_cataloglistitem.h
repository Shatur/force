/********************************************************************************
** Form generated from reading UI file 'cataloglistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGLISTITEM_H
#define UI_CATALOGLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatalogListItem
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QLabel *ruleLbl;

    void setupUi(QWidget *CatalogListItem)
    {
        if (CatalogListItem->objectName().isEmpty())
            CatalogListItem->setObjectName(QStringLiteral("CatalogListItem"));
        CatalogListItem->resize(201, 52);
        CatalogListItem->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(CatalogListItem);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(CatalogListItem);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameLabel = new QLabel(frame);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        nameLabel->setFont(font);

        verticalLayout_2->addWidget(nameLabel);

        ruleLbl = new QLabel(frame);
        ruleLbl->setObjectName(QStringLiteral("ruleLbl"));
        ruleLbl->setWordWrap(true);

        verticalLayout_2->addWidget(ruleLbl);


        verticalLayout->addWidget(frame);


        retranslateUi(CatalogListItem);

        QMetaObject::connectSlotsByName(CatalogListItem);
    } // setupUi

    void retranslateUi(QWidget *CatalogListItem)
    {
        CatalogListItem->setWindowTitle(QApplication::translate("CatalogListItem", "Form", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("CatalogListItem", "TextLabel", Q_NULLPTR));
        ruleLbl->setText(QApplication::translate("CatalogListItem", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CatalogListItem: public Ui_CatalogListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGLISTITEM_H
