/********************************************************************************
** Form generated from reading UI file 'reclamation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECLAMATION_H
#define UI_RECLAMATION_H

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

class Ui_Reclamation
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
    QLabel *addressLbl;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLabel *nameLbl;
    QLabel *infoLbl;
    QPushButton *goReportBtn;
    QFrame *line;

    void setupUi(QWidget *Reclamation)
    {
        if (Reclamation->objectName().isEmpty())
            Reclamation->setObjectName(QStringLiteral("Reclamation"));
        Reclamation->resize(267, 191);
        verticalLayout = new QVBoxLayout(Reclamation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(Reclamation);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateLbl = new QLabel(Reclamation);
        dateLbl->setObjectName(QStringLiteral("dateLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateLbl);

        label_2 = new QLabel(Reclamation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cityLbl = new QLabel(Reclamation);
        cityLbl->setObjectName(QStringLiteral("cityLbl"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cityLbl);

        label_3 = new QLabel(Reclamation);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        shopLbl = new QLabel(Reclamation);
        shopLbl->setObjectName(QStringLiteral("shopLbl"));

        formLayout->setWidget(2, QFormLayout::FieldRole, shopLbl);


        verticalLayout->addLayout(formLayout);

        addressLbl = new QLabel(Reclamation);
        addressLbl->setObjectName(QStringLiteral("addressLbl"));

        verticalLayout->addWidget(addressLbl);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(Reclamation);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        nameLbl = new QLabel(Reclamation);
        nameLbl->setObjectName(QStringLiteral("nameLbl"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nameLbl);


        verticalLayout->addLayout(formLayout_2);

        infoLbl = new QLabel(Reclamation);
        infoLbl->setObjectName(QStringLiteral("infoLbl"));
        infoLbl->setWordWrap(true);

        verticalLayout->addWidget(infoLbl);

        goReportBtn = new QPushButton(Reclamation);
        goReportBtn->setObjectName(QStringLiteral("goReportBtn"));

        verticalLayout->addWidget(goReportBtn);

        line = new QFrame(Reclamation);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(Reclamation);

        QMetaObject::connectSlotsByName(Reclamation);
    } // setupUi

    void retranslateUi(QWidget *Reclamation)
    {
        Reclamation->setWindowTitle(QApplication::translate("Reclamation", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Reclamation", "\320\224\320\260\321\202\320\260:", Q_NULLPTR));
        dateLbl->setText(QApplication::translate("Reclamation", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Reclamation", "\320\234\321\226\321\201\321\202\320\276:", Q_NULLPTR));
        cityLbl->setText(QApplication::translate("Reclamation", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Reclamation", "\320\242\320\242:", Q_NULLPTR));
        shopLbl->setText(QApplication::translate("Reclamation", "TextLabel", Q_NULLPTR));
        addressLbl->setText(QApplication::translate("Reclamation", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Reclamation", "\320\221\321\200\320\265\320\275\320\264:", Q_NULLPTR));
        nameLbl->setText(QApplication::translate("Reclamation", "TextLabel", Q_NULLPTR));
        infoLbl->setText(QApplication::translate("Reclamation", "TextLabel", Q_NULLPTR));
        goReportBtn->setText(QApplication::translate("Reclamation", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\275\321\203\321\202\320\270 \320\267\320\262\321\226\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Reclamation: public Ui_Reclamation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECLAMATION_H
