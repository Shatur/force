/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <widgets/pixmaplabel.h>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *mainStack;
    QWidget *loginPage;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    PixmapLabel *logo;
    QLabel *loginErrorLabel;
    QLineEdit *loginLE;
    QLineEdit *passwordLE;
    QPushButton *loginBtn;
    QSpacerItem *verticalSpacer_2;
    QLabel *versionLabel;
    QWidget *viewsPage;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *viewsStack;
    QWidget *routesPage;
    QWidget *waitingPage;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *dataSyncPAge;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_5;
    PixmapLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_7;
    QLabel *commonLabel;
    QProgressBar *commonProgress;
    QLabel *currentLabel;
    QProgressBar *currentProgress;
    QSpacerItem *verticalSpacer_6;
    QWidget *photoPage;
    QVBoxLayout *verticalLayout_5;
    QQuickWidget *qmlcam;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/app_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mainStack = new QStackedWidget(centralWidget);
        mainStack->setObjectName(QStringLiteral("mainStack"));
        mainStack->setLineWidth(0);
        loginPage = new QWidget();
        loginPage->setObjectName(QStringLiteral("loginPage"));
        verticalLayout = new QVBoxLayout(loginPage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logo = new PixmapLabel(loginPage);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/pics/logo_2.png")));

        verticalLayout->addWidget(logo);

        loginErrorLabel = new QLabel(loginPage);
        loginErrorLabel->setObjectName(QStringLiteral("loginErrorLabel"));
        QFont font;
        font.setUnderline(true);
        loginErrorLabel->setFont(font);
        loginErrorLabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        loginErrorLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loginErrorLabel);

        loginLE = new QLineEdit(loginPage);
        loginLE->setObjectName(QStringLiteral("loginLE"));

        verticalLayout->addWidget(loginLE);

        passwordLE = new QLineEdit(loginPage);
        passwordLE->setObjectName(QStringLiteral("passwordLE"));
        passwordLE->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout->addWidget(passwordLE);

        loginBtn = new QPushButton(loginPage);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        verticalLayout->addWidget(loginBtn);

        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        versionLabel = new QLabel(loginPage);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setTextFormat(Qt::RichText);
        versionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        versionLabel->setWordWrap(true);

        verticalLayout->addWidget(versionLabel);

        mainStack->addWidget(loginPage);
        viewsPage = new QWidget();
        viewsPage->setObjectName(QStringLiteral("viewsPage"));
        verticalLayout_3 = new QVBoxLayout(viewsPage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        viewsStack = new QStackedWidget(viewsPage);
        viewsStack->setObjectName(QStringLiteral("viewsStack"));
        routesPage = new QWidget();
        routesPage->setObjectName(QStringLiteral("routesPage"));
        viewsStack->addWidget(routesPage);

        verticalLayout_3->addWidget(viewsStack);

        mainStack->addWidget(viewsPage);
        waitingPage = new QWidget();
        waitingPage->setObjectName(QStringLiteral("waitingPage"));
        verticalLayout_4 = new QVBoxLayout(waitingPage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        label = new QLabel(waitingPage);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pics/waiting.png")));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(waitingPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        mainStack->addWidget(waitingPage);
        dataSyncPAge = new QWidget();
        dataSyncPAge->setObjectName(QStringLiteral("dataSyncPAge"));
        verticalLayout_6 = new QVBoxLayout(dataSyncPAge);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer_5 = new QSpacerItem(316, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        label_4 = new PixmapLabel(dataSyncPAge);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/pics/downloading.png")));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_4);

        label_3 = new QLabel(dataSyncPAge);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);

        verticalSpacer_7 = new QSpacerItem(316, 32, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_7);

        commonLabel = new QLabel(dataSyncPAge);
        commonLabel->setObjectName(QStringLiteral("commonLabel"));

        verticalLayout_6->addWidget(commonLabel);

        commonProgress = new QProgressBar(dataSyncPAge);
        commonProgress->setObjectName(QStringLiteral("commonProgress"));
        commonProgress->setValue(24);

        verticalLayout_6->addWidget(commonProgress);

        currentLabel = new QLabel(dataSyncPAge);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));

        verticalLayout_6->addWidget(currentLabel);

        currentProgress = new QProgressBar(dataSyncPAge);
        currentProgress->setObjectName(QStringLiteral("currentProgress"));
        currentProgress->setValue(24);

        verticalLayout_6->addWidget(currentProgress);

        verticalSpacer_6 = new QSpacerItem(316, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);

        mainStack->addWidget(dataSyncPAge);
        photoPage = new QWidget();
        photoPage->setObjectName(QStringLiteral("photoPage"));
        verticalLayout_5 = new QVBoxLayout(photoPage);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        qmlcam = new QQuickWidget(photoPage);
        qmlcam->setObjectName(QStringLiteral("qmlcam"));
        qmlcam->setFocusPolicy(Qt::NoFocus);
        qmlcam->setResizeMode(QQuickWidget::SizeRootObjectToView);

        verticalLayout_5->addWidget(qmlcam);

        mainStack->addWidget(photoPage);

        verticalLayout_2->addWidget(mainStack);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        mainStack->setCurrentIndex(4);
        viewsStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Force", Q_NULLPTR));
        logo->setText(QString());
        loginErrorLabel->setText(QString());
        loginLE->setText(QString());
        loginLE->setPlaceholderText(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", Q_NULLPTR));
        passwordLE->setText(QString());
        passwordLE->setPlaceholderText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("MainWindow", "\320\243\320\262\321\226\320\271\321\202\320\270", Q_NULLPTR));
        versionLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\221\321\203\320\264\321\214 \320\273\320\260\321\201\320\272\320\260 \320\267\320\260\321\207\320\265\320\272\320\260\320\271\321\202\320\265...", Q_NULLPTR));
        label_4->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\320\242\321\200\320\270\320\262\320\260\321\224 \320\276\321\202\321\200\320\270\320\274\320\260\320\275\320\275\321\217 \320\264\320\260\320\275\320\270\321\205...", Q_NULLPTR));
        commonLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        currentLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
