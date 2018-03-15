/********************************************************************************
** Form generated from reading UI file 'reportitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTITEM_H
#define UI_REPORTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportItem
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *uiLabelName;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *uiLfColumn;
    QVBoxLayout *uiRgColumn;

    void setupUi(QWidget *ReportItem)
    {
        if (ReportItem->objectName().isEmpty())
            ReportItem->setObjectName(QStringLiteral("ReportItem"));
        ReportItem->resize(183, 71);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReportItem->sizePolicy().hasHeightForWidth());
        ReportItem->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ReportItem);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        uiLabelName = new QLabel(ReportItem);
        uiLabelName->setObjectName(QStringLiteral("uiLabelName"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(uiLabelName->sizePolicy().hasHeightForWidth());
        uiLabelName->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(uiLabelName);

        line = new QFrame(ReportItem);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        uiLfColumn = new QVBoxLayout();
        uiLfColumn->setObjectName(QStringLiteral("uiLfColumn"));

        horizontalLayout->addLayout(uiLfColumn);

        uiRgColumn = new QVBoxLayout();
        uiRgColumn->setObjectName(QStringLiteral("uiRgColumn"));

        horizontalLayout->addLayout(uiRgColumn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReportItem);

        QMetaObject::connectSlotsByName(ReportItem);
    } // setupUi

    void retranslateUi(QWidget *ReportItem)
    {
        ReportItem->setWindowTitle(QApplication::translate("ReportItem", "Form", Q_NULLPTR));
        uiLabelName->setText(QApplication::translate("ReportItem", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportItem: public Ui_ReportItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTITEM_H
