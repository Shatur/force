/********************************************************************************
** Form generated from reading UI file 'selectbrand.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTBRAND_H
#define UI_SELECTBRAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectBrand
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QListWidget *brandsList;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *backButton;
    QToolButton *emptyReportBtn;
    QToolButton *goReportBtn;

    void setupUi(QWidget *SelectBrand)
    {
        if (SelectBrand->objectName().isEmpty())
            SelectBrand->setObjectName(QStringLiteral("SelectBrand"));
        SelectBrand->resize(400, 600);
        verticalLayout = new QVBoxLayout(SelectBrand);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(SelectBrand);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame);

        brandsList = new QListWidget(SelectBrand);
        brandsList->setObjectName(QStringLiteral("brandsList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(brandsList->sizePolicy().hasHeightForWidth());
        brandsList->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(brandsList);

        frame_2 = new QFrame(SelectBrand);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QToolButton(frame_2);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);
        backButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 127);"));

        horizontalLayout->addWidget(backButton);

        emptyReportBtn = new QToolButton(frame_2);
        emptyReportBtn->setObjectName(QStringLiteral("emptyReportBtn"));
        sizePolicy2.setHeightForWidth(emptyReportBtn->sizePolicy().hasHeightForWidth());
        emptyReportBtn->setSizePolicy(sizePolicy2);
        emptyReportBtn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 127);"));

        horizontalLayout->addWidget(emptyReportBtn);

        goReportBtn = new QToolButton(frame_2);
        goReportBtn->setObjectName(QStringLiteral("goReportBtn"));
        sizePolicy2.setHeightForWidth(goReportBtn->sizePolicy().hasHeightForWidth());
        goReportBtn->setSizePolicy(sizePolicy2);
        goReportBtn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 127);"));

        horizontalLayout->addWidget(goReportBtn);


        verticalLayout->addWidget(frame_2);


        retranslateUi(SelectBrand);

        QMetaObject::connectSlotsByName(SelectBrand);
    } // setupUi

    void retranslateUi(QWidget *SelectBrand)
    {
        SelectBrand->setWindowTitle(QApplication::translate("SelectBrand", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SelectBrand", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\261\321\200\320\265\320\275\320\264", Q_NULLPTR));
        backButton->setText(QApplication::translate("SelectBrand", "\320\237\320\276\320\272\320\270\320\275\321\203\321\202\320\270 \320\242\320\242", Q_NULLPTR));
        emptyReportBtn->setText(QApplication::translate("SelectBrand", "\320\237\320\276\321\200\320\276\320\266\320\275\321\213\320\271 \320\267\320\262\321\226\321\202", Q_NULLPTR));
        goReportBtn->setText(QApplication::translate("SelectBrand", "\320\224\320\276 \320\267\320\262\321\226\321\202\321\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectBrand: public Ui_SelectBrand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTBRAND_H
