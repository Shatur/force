/********************************************************************************
** Form generated from reading UI file 'allcommentswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLCOMMENTSWIDGET_H
#define UI_ALLCOMMENTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllCommentsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *reportLbl;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *commentsCountLbl;
    QLabel *textLbl;
    QPushButton *goReportBtn;
    QFrame *line;

    void setupUi(QWidget *AllCommentsWidget)
    {
        if (AllCommentsWidget->objectName().isEmpty())
            AllCommentsWidget->setObjectName(QStringLiteral("AllCommentsWidget"));
        AllCommentsWidget->resize(228, 93);
        verticalLayout = new QVBoxLayout(AllCommentsWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        reportLbl = new QLabel(AllCommentsWidget);
        reportLbl->setObjectName(QStringLiteral("reportLbl"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        reportLbl->setFont(font);
        reportLbl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(reportLbl);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(AllCommentsWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        commentsCountLbl = new QLabel(AllCommentsWidget);
        commentsCountLbl->setObjectName(QStringLiteral("commentsCountLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, commentsCountLbl);


        verticalLayout->addLayout(formLayout);

        textLbl = new QLabel(AllCommentsWidget);
        textLbl->setObjectName(QStringLiteral("textLbl"));
        textLbl->setWordWrap(true);

        verticalLayout->addWidget(textLbl);

        goReportBtn = new QPushButton(AllCommentsWidget);
        goReportBtn->setObjectName(QStringLiteral("goReportBtn"));

        verticalLayout->addWidget(goReportBtn);

        line = new QFrame(AllCommentsWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(AllCommentsWidget);

        QMetaObject::connectSlotsByName(AllCommentsWidget);
    } // setupUi

    void retranslateUi(QWidget *AllCommentsWidget)
    {
        AllCommentsWidget->setWindowTitle(QApplication::translate("AllCommentsWidget", "Form", Q_NULLPTR));
        reportLbl->setText(QApplication::translate("AllCommentsWidget", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("AllCommentsWidget", "\320\232\320\276\320\274\320\265\320\275\321\202\320\260\321\200\321\226\320\262:", Q_NULLPTR));
        commentsCountLbl->setText(QString());
        textLbl->setText(QApplication::translate("AllCommentsWidget", "TextLabel", Q_NULLPTR));
        goReportBtn->setText(QApplication::translate("AllCommentsWidget", "\320\224\320\276 \320\267\320\262\321\226\321\202\321\203...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AllCommentsWidget: public Ui_AllCommentsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLCOMMENTSWIDGET_H
