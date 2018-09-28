/********************************************************************************
** Form generated from reading UI file 'routeitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTEITEMWIDGET_H
#define UI_ROUTEITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RouteItemWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *regionLbl;
    QLabel *cityLbl;
    QLabel *shopLbl;
    QLabel *addressLbl;
    QPushButton *doReportBtn;
    QFrame *line;

    void setupUi(QWidget *RouteItemWidget)
    {
        if (RouteItemWidget->objectName().isEmpty())
            RouteItemWidget->setObjectName(QStringLiteral("RouteItemWidget"));
        RouteItemWidget->resize(211, 121);
        verticalLayout_2 = new QVBoxLayout(RouteItemWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        regionLbl = new QLabel(RouteItemWidget);
        regionLbl->setObjectName(QStringLiteral("regionLbl"));

        verticalLayout->addWidget(regionLbl);

        cityLbl = new QLabel(RouteItemWidget);
        cityLbl->setObjectName(QStringLiteral("cityLbl"));

        verticalLayout->addWidget(cityLbl);

        shopLbl = new QLabel(RouteItemWidget);
        shopLbl->setObjectName(QStringLiteral("shopLbl"));

        verticalLayout->addWidget(shopLbl);

        addressLbl = new QLabel(RouteItemWidget);
        addressLbl->setObjectName(QStringLiteral("addressLbl"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        addressLbl->setFont(font);

        verticalLayout->addWidget(addressLbl);


        horizontalLayout->addLayout(verticalLayout);

        doReportBtn = new QPushButton(RouteItemWidget);
        doReportBtn->setObjectName(QStringLiteral("doReportBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doReportBtn->sizePolicy().hasHeightForWidth());
        doReportBtn->setSizePolicy(sizePolicy);
        doReportBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/original/route_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        doReportBtn->setIcon(icon);
        doReportBtn->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(doReportBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(RouteItemWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(RouteItemWidget);

        QMetaObject::connectSlotsByName(RouteItemWidget);
    } // setupUi

    void retranslateUi(QWidget *RouteItemWidget)
    {
        RouteItemWidget->setWindowTitle(QApplication::translate("RouteItemWidget", "Form", Q_NULLPTR));
        regionLbl->setText(QApplication::translate("RouteItemWidget", "TextLabel", Q_NULLPTR));
        cityLbl->setText(QApplication::translate("RouteItemWidget", "TextLabel", Q_NULLPTR));
        shopLbl->setText(QApplication::translate("RouteItemWidget", "TextLabel", Q_NULLPTR));
        addressLbl->setText(QApplication::translate("RouteItemWidget", "TextLabel", Q_NULLPTR));
        doReportBtn->setText(QApplication::translate("RouteItemWidget", "\320\243\320\262\321\226\320\271\321\202\320\270 \321\203 \320\242\320\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RouteItemWidget: public Ui_RouteItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTEITEMWIDGET_H
