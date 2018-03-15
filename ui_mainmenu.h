/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

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
#include <widgets/pixmaplabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *top_frame;
    QHBoxLayout *horizontalLayout;
    PixmapLabel *label;
    QLabel *AccountLabel;
    QFrame *menu_frame;
    QVBoxLayout *verticalLayout;
    QPushButton *routesBtn;
    QPushButton *tasksBtn;
    QPushButton *reclamationBtn;
    QFrame *line;
    QPushButton *eventsBtn;
    QPushButton *archivmentsBtn;
    QPushButton *commentsBtn;
    QFrame *line_3;
    QPushButton *settingsBtn;
    QPushButton *syncButton;
    QFrame *line_4;
    QPushButton *exitBtn;
    QFrame *line_2;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(589, 734);
        verticalLayout_2 = new QVBoxLayout(MainMenu);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        top_frame = new QFrame(MainMenu);
        top_frame->setObjectName(QStringLiteral("top_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setStyleSheet(QLatin1String("/*background-color: rgb(0, 0, 127);*/\n"
""));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(top_frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new PixmapLabel(top_frame);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pics/logo_3.png")));

        horizontalLayout->addWidget(label);

        AccountLabel = new QLabel(top_frame);
        AccountLabel->setObjectName(QStringLiteral("AccountLabel"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        AccountLabel->setFont(font);
        AccountLabel->setStyleSheet(QLatin1String("/*color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 127);*/"));

        horizontalLayout->addWidget(AccountLabel);


        verticalLayout_2->addWidget(top_frame);

        menu_frame = new QFrame(MainMenu);
        menu_frame->setObjectName(QStringLiteral("menu_frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(90);
        sizePolicy1.setHeightForWidth(menu_frame->sizePolicy().hasHeightForWidth());
        menu_frame->setSizePolicy(sizePolicy1);
        menu_frame->setFrameShape(QFrame::StyledPanel);
        menu_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(menu_frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        routesBtn = new QPushButton(menu_frame);
        routesBtn->setObjectName(QStringLiteral("routesBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(routesBtn->sizePolicy().hasHeightForWidth());
        routesBtn->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/original/route_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        routesBtn->setIcon(icon);
        routesBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(routesBtn);

        tasksBtn = new QPushButton(menu_frame);
        tasksBtn->setObjectName(QStringLiteral("tasksBtn"));
        sizePolicy2.setHeightForWidth(tasksBtn->sizePolicy().hasHeightForWidth());
        tasksBtn->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pics/original/task_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        tasksBtn->setIcon(icon1);
        tasksBtn->setIconSize(QSize(48, 48));
        tasksBtn->setFlat(false);

        verticalLayout->addWidget(tasksBtn);

        reclamationBtn = new QPushButton(menu_frame);
        reclamationBtn->setObjectName(QStringLiteral("reclamationBtn"));
        sizePolicy2.setHeightForWidth(reclamationBtn->sizePolicy().hasHeightForWidth());
        reclamationBtn->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pics/original/bad_route_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        reclamationBtn->setIcon(icon2);
        reclamationBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(reclamationBtn);

        line = new QFrame(menu_frame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        eventsBtn = new QPushButton(menu_frame);
        eventsBtn->setObjectName(QStringLiteral("eventsBtn"));
        sizePolicy2.setHeightForWidth(eventsBtn->sizePolicy().hasHeightForWidth());
        eventsBtn->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pics/original/event_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        eventsBtn->setIcon(icon3);
        eventsBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(eventsBtn);

        archivmentsBtn = new QPushButton(menu_frame);
        archivmentsBtn->setObjectName(QStringLiteral("archivmentsBtn"));
        archivmentsBtn->setEnabled(true);
        sizePolicy2.setHeightForWidth(archivmentsBtn->sizePolicy().hasHeightForWidth());
        archivmentsBtn->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/pics/original/achievement_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        archivmentsBtn->setIcon(icon4);
        archivmentsBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(archivmentsBtn);

        commentsBtn = new QPushButton(menu_frame);
        commentsBtn->setObjectName(QStringLiteral("commentsBtn"));
        sizePolicy2.setHeightForWidth(commentsBtn->sizePolicy().hasHeightForWidth());
        commentsBtn->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/pics/original/comment_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        commentsBtn->setIcon(icon5);
        commentsBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(commentsBtn);

        line_3 = new QFrame(menu_frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        settingsBtn = new QPushButton(menu_frame);
        settingsBtn->setObjectName(QStringLiteral("settingsBtn"));
        sizePolicy2.setHeightForWidth(settingsBtn->sizePolicy().hasHeightForWidth());
        settingsBtn->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/pics/original/settings1_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsBtn->setIcon(icon6);
        settingsBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(settingsBtn);

        syncButton = new QPushButton(menu_frame);
        syncButton->setObjectName(QStringLiteral("syncButton"));
        sizePolicy2.setHeightForWidth(syncButton->sizePolicy().hasHeightForWidth());
        syncButton->setSizePolicy(sizePolicy2);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/pics/sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        syncButton->setIcon(icon7);
        syncButton->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(syncButton);

        line_4 = new QFrame(menu_frame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        exitBtn = new QPushButton(menu_frame);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        sizePolicy2.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy2);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/pics/original/logout_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitBtn->setIcon(icon8);
        exitBtn->setIconSize(QSize(48, 48));

        verticalLayout->addWidget(exitBtn);

        line_2 = new QFrame(menu_frame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);


        verticalLayout_2->addWidget(menu_frame);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Form", Q_NULLPTR));
        label->setText(QString());
        AccountLabel->setText(QApplication::translate("MainMenu", "TextLabel", Q_NULLPTR));
        routesBtn->setText(QApplication::translate("MainMenu", "\320\234\320\260\321\200\321\210\321\200\321\203\321\202\320\270", Q_NULLPTR));
        tasksBtn->setText(QApplication::translate("MainMenu", "\320\227\320\260\320\264\320\260\321\207\321\226", Q_NULLPTR));
        reclamationBtn->setText(QApplication::translate("MainMenu", "\320\240\320\265\320\272\320\273\320\260\320\274\320\260\321\206\321\226\321\227", Q_NULLPTR));
        eventsBtn->setText(QApplication::translate("MainMenu", "\320\237\320\276\320\264\321\226\321\227", Q_NULLPTR));
        archivmentsBtn->setText(QApplication::translate("MainMenu", "\320\224\320\276\321\201\321\217\320\263\320\275\320\265\320\275\320\275\321\217", Q_NULLPTR));
        commentsBtn->setText(QApplication::translate("MainMenu", "\320\232\320\276\320\274\320\265\320\275\321\202\320\260\321\200\321\226", Q_NULLPTR));
        settingsBtn->setText(QApplication::translate("MainMenu", "\320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", Q_NULLPTR));
        syncButton->setText(QApplication::translate("MainMenu", "\320\241\320\270\320\275\321\205\321\200\320\276\320\275\321\226\320\267\321\203\320\262\320\260\321\202\320\270", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("MainMenu", "\320\222\320\270\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
