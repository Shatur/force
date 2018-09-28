/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fontSizeEdit;
    QPushButton *plusBtn;
    QPushButton *minusBtn;
    QLabel *exampleLbl;
    QSpacerItem *verticalSpacer;
    QPushButton *backBtn;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(451, 480);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        fontSizeEdit = new QLineEdit(Settings);
        fontSizeEdit->setObjectName(QStringLiteral("fontSizeEdit"));
        fontSizeEdit->setFont(font);

        horizontalLayout->addWidget(fontSizeEdit);

        plusBtn = new QPushButton(Settings);
        plusBtn->setObjectName(QStringLiteral("plusBtn"));
        plusBtn->setFont(font);

        horizontalLayout->addWidget(plusBtn);

        minusBtn = new QPushButton(Settings);
        minusBtn->setObjectName(QStringLiteral("minusBtn"));
        minusBtn->setFont(font);

        horizontalLayout->addWidget(minusBtn);


        verticalLayout->addLayout(horizontalLayout);

        exampleLbl = new QLabel(Settings);
        exampleLbl->setObjectName(QStringLiteral("exampleLbl"));

        verticalLayout->addWidget(exampleLbl);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        backBtn = new QPushButton(Settings);
        backBtn->setObjectName(QStringLiteral("backBtn"));
        backBtn->setMinimumSize(QSize(0, 70));
        backBtn->setFont(font);

        verticalLayout->addWidget(backBtn);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Settings", "\320\240\320\276\320\267\320\274\321\226\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 \320\262 px", Q_NULLPTR));
        plusBtn->setText(QApplication::translate("Settings", "+", Q_NULLPTR));
        minusBtn->setText(QApplication::translate("Settings", "-", Q_NULLPTR));
        exampleLbl->setText(QApplication::translate("Settings", "\320\237\321\200\320\270\320\272\320\273\320\260\320\264 \321\200\320\276\320\267\320\274\321\226\321\200\321\203 \321\202\320\265\320\272\321\201\321\202\321\203", Q_NULLPTR));
        backBtn->setText(QApplication::translate("Settings", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
