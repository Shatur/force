/********************************************************************************
** Form generated from reading UI file 'events.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTS_H
#define UI_EVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Events
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *top_frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QListWidget *ev_spaceList;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *ev_target_taskList;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QListWidget *ev_actionList;
    QFrame *bottom_frame;
    QVBoxLayout *verticalLayout_5;
    QToolButton *backButton;

    void setupUi(QWidget *Events)
    {
        if (Events->objectName().isEmpty())
            Events->setObjectName(QStringLiteral("Events"));
        Events->resize(400, 600);
        verticalLayout = new QVBoxLayout(Events);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        top_frame = new QFrame(Events);
        top_frame->setObjectName(QStringLiteral("top_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(top_frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(top_frame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(top_frame);

        tabWidget = new QTabWidget(Events);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ev_spaceList = new QListWidget(tab);
        ev_spaceList->setObjectName(QStringLiteral("ev_spaceList"));
        sizePolicy1.setHeightForWidth(ev_spaceList->sizePolicy().hasHeightForWidth());
        ev_spaceList->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(ev_spaceList);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ev_target_taskList = new QListWidget(tab_2);
        ev_target_taskList->setObjectName(QStringLiteral("ev_target_taskList"));

        verticalLayout_3->addWidget(ev_target_taskList);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        ev_actionList = new QListWidget(tab_3);
        ev_actionList->setObjectName(QStringLiteral("ev_actionList"));

        verticalLayout_4->addWidget(ev_actionList);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        bottom_frame = new QFrame(Events);
        bottom_frame->setObjectName(QStringLiteral("bottom_frame"));
        sizePolicy.setHeightForWidth(bottom_frame->sizePolicy().hasHeightForWidth());
        bottom_frame->setSizePolicy(sizePolicy);
        bottom_frame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        bottom_frame->setFrameShape(QFrame::StyledPanel);
        bottom_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(bottom_frame);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        backButton = new QToolButton(bottom_frame);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(backButton);


        verticalLayout->addWidget(bottom_frame);


        retranslateUi(Events);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Events);
    } // setupUi

    void retranslateUi(QWidget *Events)
    {
        Events->setWindowTitle(QApplication::translate("Events", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Events", "\320\237\320\276\320\264\321\226\321\227", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Events", "\320\224\320\276\320\264\320\260\321\202\320\272\320\276\320\262\320\265 \320\274\321\226\321\201\321\206\320\265", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Events", "\320\246\321\226\320\273\321\214\320\276\320\262\320\260 \320\267\320\260\320\264\320\260\321\207\320\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Events", "\320\220\320\272\321\206\321\226\321\217", Q_NULLPTR));
        backButton->setText(QApplication::translate("Events", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Events: public Ui_Events {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTS_H
