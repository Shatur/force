/********************************************************************************
** Form generated from reading UI file 'reportcommentswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTCOMMENTSWIDGET_H
#define UI_REPORTCOMMENTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportCommentsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *borderGb;
    QVBoxLayout *verticalLayout_2;
    QLabel *text;

    void setupUi(QWidget *ReportCommentsWidget)
    {
        if (ReportCommentsWidget->objectName().isEmpty())
            ReportCommentsWidget->setObjectName(QStringLiteral("ReportCommentsWidget"));
        ReportCommentsWidget->resize(244, 66);
        ReportCommentsWidget->setStyleSheet(QStringLiteral("borderGb: { border-radius: 20px;border: 1px solid gray; }"));
        verticalLayout = new QVBoxLayout(ReportCommentsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 0, 6, 6);
        borderGb = new QGroupBox(ReportCommentsWidget);
        borderGb->setObjectName(QStringLiteral("borderGb"));
        borderGb->setEnabled(true);
        borderGb->setStyleSheet(QStringLiteral("borderGb: { border-radius: 20px; border: 1px solid gray; };"));
        verticalLayout_2 = new QVBoxLayout(borderGb);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        text = new QLabel(borderGb);
        text->setObjectName(QStringLiteral("text"));
        text->setWordWrap(true);

        verticalLayout_2->addWidget(text);


        verticalLayout->addWidget(borderGb);


        retranslateUi(ReportCommentsWidget);

        QMetaObject::connectSlotsByName(ReportCommentsWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportCommentsWidget)
    {
        ReportCommentsWidget->setWindowTitle(QApplication::translate("ReportCommentsWidget", "Form", Q_NULLPTR));
        borderGb->setTitle(QApplication::translate("ReportCommentsWidget", "01.06.2016 11:10", Q_NULLPTR));
        text->setText(QApplication::translate("ReportCommentsWidget", "This is a demo text", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportCommentsWidget: public Ui_ReportCommentsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTCOMMENTSWIDGET_H
