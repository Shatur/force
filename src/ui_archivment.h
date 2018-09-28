/********************************************************************************
** Form generated from reading UI file 'archivment.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVMENT_H
#define UI_ARCHIVMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Archivment
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *type_sLbl;
    QLabel *typeLbl;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *statusLbl;
    QLabel *label;
    QLabel *cityLbl;
    QLabel *label_2;
    QLabel *shopLbl;
    QLabel *label_3;
    QLabel *addressLbl;
    QLabel *label_4;
    QLabel *clientLbl;
    QLabel *descrLbl;
    QFrame *line;

    void setupUi(QWidget *Archivment)
    {
        if (Archivment->objectName().isEmpty())
            Archivment->setObjectName(QStringLiteral("Archivment"));
        Archivment->resize(167, 168);
        verticalLayout = new QVBoxLayout(Archivment);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_5 = new QLabel(Archivment);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        type_sLbl = new QLabel(Archivment);
        type_sLbl->setObjectName(QStringLiteral("type_sLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, type_sLbl);


        verticalLayout->addLayout(formLayout);

        typeLbl = new QLabel(Archivment);
        typeLbl->setObjectName(QStringLiteral("typeLbl"));
        typeLbl->setWordWrap(true);

        verticalLayout->addWidget(typeLbl);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_6 = new QLabel(Archivment);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        statusLbl = new QLabel(Archivment);
        statusLbl->setObjectName(QStringLiteral("statusLbl"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, statusLbl);

        label = new QLabel(Archivment);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        cityLbl = new QLabel(Archivment);
        cityLbl->setObjectName(QStringLiteral("cityLbl"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cityLbl);

        label_2 = new QLabel(Archivment);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        shopLbl = new QLabel(Archivment);
        shopLbl->setObjectName(QStringLiteral("shopLbl"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, shopLbl);

        label_3 = new QLabel(Archivment);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_3);

        addressLbl = new QLabel(Archivment);
        addressLbl->setObjectName(QStringLiteral("addressLbl"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, addressLbl);

        label_4 = new QLabel(Archivment);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        clientLbl = new QLabel(Archivment);
        clientLbl->setObjectName(QStringLiteral("clientLbl"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, clientLbl);


        verticalLayout->addLayout(formLayout_2);

        descrLbl = new QLabel(Archivment);
        descrLbl->setObjectName(QStringLiteral("descrLbl"));
        descrLbl->setFont(font);
        descrLbl->setWordWrap(true);

        verticalLayout->addWidget(descrLbl);

        line = new QFrame(Archivment);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(Archivment);

        QMetaObject::connectSlotsByName(Archivment);
    } // setupUi

    void retranslateUi(QWidget *Archivment)
    {
        Archivment->setWindowTitle(QApplication::translate("Archivment", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("Archivment", "\320\242\320\270\320\277:", Q_NULLPTR));
        type_sLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        typeLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Archivment", "\320\241\321\202\320\260\320\275:", Q_NULLPTR));
        statusLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("Archivment", "\320\234\321\226\321\201\321\202\320\276:", Q_NULLPTR));
        cityLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Archivment", "\320\242\320\242:", Q_NULLPTR));
        shopLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Archivment", "\320\220\320\264\321\200\320\265\321\201\320\260:", Q_NULLPTR));
        addressLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Archivment", "\320\232\320\273\321\226\321\224\320\275\321\202:", Q_NULLPTR));
        clientLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
        descrLbl->setText(QApplication::translate("Archivment", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Archivment: public Ui_Archivment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVMENT_H
