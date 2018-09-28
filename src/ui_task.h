/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

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

class Ui_Task
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *dateLbl;
    QLabel *label_2;
    QLabel *cityLbl;
    QLabel *label_3;
    QLabel *shopLbl;
    QLabel *label_4;
    QLabel *addressLbl;
    QLabel *label_5;
    QLabel *clientLbl;
    QLabel *label_6;
    QLabel *authorLbl;
    QLabel *label_7;
    QLabel *stateLbl;
    QLabel *taskLbl;
    QPushButton *goReportBtn;
    QFrame *line;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QStringLiteral("Task"));
        Task->resize(211, 186);
        verticalLayout = new QVBoxLayout(Task);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(Task);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateLbl = new QLabel(Task);
        dateLbl->setObjectName(QStringLiteral("dateLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateLbl);

        label_2 = new QLabel(Task);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cityLbl = new QLabel(Task);
        cityLbl->setObjectName(QStringLiteral("cityLbl"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cityLbl);

        label_3 = new QLabel(Task);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        shopLbl = new QLabel(Task);
        shopLbl->setObjectName(QStringLiteral("shopLbl"));

        formLayout->setWidget(2, QFormLayout::FieldRole, shopLbl);

        label_4 = new QLabel(Task);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        addressLbl = new QLabel(Task);
        addressLbl->setObjectName(QStringLiteral("addressLbl"));

        formLayout->setWidget(3, QFormLayout::FieldRole, addressLbl);

        label_5 = new QLabel(Task);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        clientLbl = new QLabel(Task);
        clientLbl->setObjectName(QStringLiteral("clientLbl"));

        formLayout->setWidget(4, QFormLayout::FieldRole, clientLbl);

        label_6 = new QLabel(Task);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        authorLbl = new QLabel(Task);
        authorLbl->setObjectName(QStringLiteral("authorLbl"));

        formLayout->setWidget(5, QFormLayout::FieldRole, authorLbl);

        label_7 = new QLabel(Task);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        stateLbl = new QLabel(Task);
        stateLbl->setObjectName(QStringLiteral("stateLbl"));

        formLayout->setWidget(6, QFormLayout::FieldRole, stateLbl);


        verticalLayout->addLayout(formLayout);

        taskLbl = new QLabel(Task);
        taskLbl->setObjectName(QStringLiteral("taskLbl"));
        taskLbl->setFont(font);
        taskLbl->setWordWrap(true);

        verticalLayout->addWidget(taskLbl);

        goReportBtn = new QPushButton(Task);
        goReportBtn->setObjectName(QStringLiteral("goReportBtn"));

        verticalLayout->addWidget(goReportBtn);

        line = new QFrame(Task);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QApplication::translate("Task", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Task", "\320\224\320\260\321\202\320\260:", Q_NULLPTR));
        dateLbl->setText(QApplication::translate("Task", "dateLbl", Q_NULLPTR));
        label_2->setText(QApplication::translate("Task", "\320\234\321\226\321\201\321\202\320\276:", Q_NULLPTR));
        cityLbl->setText(QApplication::translate("Task", "cityLbl", Q_NULLPTR));
        label_3->setText(QApplication::translate("Task", "\320\234\320\260\320\263\320\260\320\267\320\270\320\275:", Q_NULLPTR));
        shopLbl->setText(QApplication::translate("Task", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Task", "\320\220\320\264\321\200\320\265\321\201\320\260:", Q_NULLPTR));
        addressLbl->setText(QApplication::translate("Task", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("Task", "\320\232\320\273\321\226\321\215\320\275\321\202:", Q_NULLPTR));
        clientLbl->setText(QApplication::translate("Task", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Task", "\320\220\320\262\321\202\320\276\321\200:", Q_NULLPTR));
        authorLbl->setText(QApplication::translate("Task", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("Task", "\320\241\321\202\320\260\321\202\321\203\321\201:", Q_NULLPTR));
        stateLbl->setText(QApplication::translate("Task", "TextLabel", Q_NULLPTR));
        taskLbl->setText(QApplication::translate("Task", "TextLabel", Q_NULLPTR));
        goReportBtn->setText(QApplication::translate("Task", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\275\321\203\321\202\320\270 \320\267\320\262\321\226\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
