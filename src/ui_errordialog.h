/********************************************************************************
** Form generated from reading UI file 'errordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORDIALOG_H
#define UI_ERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QLabel *errorImg;
    QLabel *errorTextLbl;
    QSpacerItem *verticalSpacer_6;
    QPushButton *backButton;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *ErrorDialog)
    {
        if (ErrorDialog->objectName().isEmpty())
            ErrorDialog->setObjectName(QStringLiteral("ErrorDialog"));
        ErrorDialog->resize(306, 369);
        verticalLayout = new QVBoxLayout(ErrorDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        errorImg = new QLabel(ErrorDialog);
        errorImg->setObjectName(QStringLiteral("errorImg"));
        errorImg->setPixmap(QPixmap(QString::fromUtf8(":/pics/error.png")));
        errorImg->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(errorImg);

        errorTextLbl = new QLabel(ErrorDialog);
        errorTextLbl->setObjectName(QStringLiteral("errorTextLbl"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        errorTextLbl->setFont(font);
        errorTextLbl->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        errorTextLbl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(errorTextLbl);

        verticalSpacer_6 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        backButton = new QPushButton(ErrorDialog);
        backButton->setObjectName(QStringLiteral("backButton"));

        verticalLayout->addWidget(backButton);

        verticalSpacer_7 = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);


        retranslateUi(ErrorDialog);

        QMetaObject::connectSlotsByName(ErrorDialog);
    } // setupUi

    void retranslateUi(QWidget *ErrorDialog)
    {
        ErrorDialog->setWindowTitle(QApplication::translate("ErrorDialog", "Form", Q_NULLPTR));
        errorImg->setText(QString());
        errorTextLbl->setText(QApplication::translate("ErrorDialog", "TextLabel", Q_NULLPTR));
        backButton->setText(QApplication::translate("ErrorDialog", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\320\270\321\201\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ErrorDialog: public Ui_ErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORDIALOG_H
