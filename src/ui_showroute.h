/********************************************************************************
** Form generated from reading UI file 'showroute.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWROUTE_H
#define UI_SHOWROUTE_H

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

class Ui_ShowRoute
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *top_frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *txtLabel;
    QListWidget *routesList;
    QFrame *bottom_frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *backButton;
    QToolButton *prevDayBtn;
    QToolButton *newxDayBtn;

    void setupUi(QWidget *ShowRoute)
    {
        if (ShowRoute->objectName().isEmpty())
            ShowRoute->setObjectName(QStringLiteral("ShowRoute"));
        ShowRoute->resize(400, 600);
        verticalLayout = new QVBoxLayout(ShowRoute);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        top_frame = new QFrame(ShowRoute);
        top_frame->setObjectName(QStringLiteral("top_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setMinimumSize(QSize(0, 64));
        top_frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(top_frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(top_frame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label);

        txtLabel = new QLabel(top_frame);
        txtLabel->setObjectName(QStringLiteral("txtLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtLabel->sizePolicy().hasHeightForWidth());
        txtLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        txtLabel->setFont(font1);
        txtLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        txtLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(txtLabel);


        verticalLayout->addWidget(top_frame);

        routesList = new QListWidget(ShowRoute);
        routesList->setObjectName(QStringLiteral("routesList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(75);
        sizePolicy2.setHeightForWidth(routesList->sizePolicy().hasHeightForWidth());
        routesList->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(routesList);

        bottom_frame = new QFrame(ShowRoute);
        bottom_frame->setObjectName(QStringLiteral("bottom_frame"));
        sizePolicy.setHeightForWidth(bottom_frame->sizePolicy().hasHeightForWidth());
        bottom_frame->setSizePolicy(sizePolicy);
        bottom_frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        bottom_frame->setFrameShape(QFrame::StyledPanel);
        bottom_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(bottom_frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QToolButton(bottom_frame);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy3);
        backButton->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(backButton);

        prevDayBtn = new QToolButton(bottom_frame);
        prevDayBtn->setObjectName(QStringLiteral("prevDayBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(prevDayBtn->sizePolicy().hasHeightForWidth());
        prevDayBtn->setSizePolicy(sizePolicy4);
        prevDayBtn->setMinimumSize(QSize(0, 64));
        prevDayBtn->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout->addWidget(prevDayBtn);

        newxDayBtn = new QToolButton(bottom_frame);
        newxDayBtn->setObjectName(QStringLiteral("newxDayBtn"));
        sizePolicy4.setHeightForWidth(newxDayBtn->sizePolicy().hasHeightForWidth());
        newxDayBtn->setSizePolicy(sizePolicy4);
        newxDayBtn->setMinimumSize(QSize(0, 64));
        newxDayBtn->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout->addWidget(newxDayBtn);


        verticalLayout->addWidget(bottom_frame);


        retranslateUi(ShowRoute);

        QMetaObject::connectSlotsByName(ShowRoute);
    } // setupUi

    void retranslateUi(QWidget *ShowRoute)
    {
        ShowRoute->setWindowTitle(QApplication::translate("ShowRoute", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ShowRoute", "\320\234\320\260\321\200\321\210\321\200\321\203\321\202\320\270", Q_NULLPTR));
        txtLabel->setText(QApplication::translate("ShowRoute", "TextLabel", Q_NULLPTR));
        backButton->setText(QApplication::translate("ShowRoute", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        prevDayBtn->setText(QApplication::translate("ShowRoute", "\320\237\320\276\320\277\320\265\321\200\320\265\320\264\320\275\321\226\320\271 \320\264\320\265\320\275\321\214", Q_NULLPTR));
        newxDayBtn->setText(QApplication::translate("ShowRoute", "\320\235\320\260\321\201\321\202\321\203\320\277\320\275\320\270\320\271 \320\264\320\265\320\275\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShowRoute: public Ui_ShowRoute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWROUTE_H
