/********************************************************************************
** Form generated from reading UI file 'reclamations.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECLAMATIONS_H
#define UI_RECLAMATIONS_H

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

class Ui_Reclamations
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *topFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QListWidget *currentList;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *fixedList;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QListWidget *finalList;
    QFrame *bottomFrame;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *backButton;

    void setupUi(QWidget *Reclamations)
    {
        if (Reclamations->objectName().isEmpty())
            Reclamations->setObjectName(QStringLiteral("Reclamations"));
        Reclamations->resize(400, 640);
        verticalLayout = new QVBoxLayout(Reclamations);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topFrame = new QFrame(Reclamations);
        topFrame->setObjectName(QStringLiteral("topFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(topFrame->sizePolicy().hasHeightForWidth());
        topFrame->setSizePolicy(sizePolicy);
        topFrame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(topFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(topFrame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(topFrame);

        tabWidget = new QTabWidget(Reclamations);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setStyleSheet(QStringLiteral("QTabBar::tab { height: 100px;}"));
        tabWidget->setDocumentMode(true);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        currentList = new QListWidget(tab);
        currentList->setObjectName(QStringLiteral("currentList"));

        verticalLayout_2->addWidget(currentList);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        fixedList = new QListWidget(tab_2);
        fixedList->setObjectName(QStringLiteral("fixedList"));

        verticalLayout_3->addWidget(fixedList);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        finalList = new QListWidget(tab_3);
        finalList->setObjectName(QStringLiteral("finalList"));

        verticalLayout_4->addWidget(finalList);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        bottomFrame = new QFrame(Reclamations);
        bottomFrame->setObjectName(QStringLiteral("bottomFrame"));
        sizePolicy.setHeightForWidth(bottomFrame->sizePolicy().hasHeightForWidth());
        bottomFrame->setSizePolicy(sizePolicy);
        bottomFrame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(bottomFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        backButton = new QToolButton(bottomFrame);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(backButton);


        verticalLayout->addWidget(bottomFrame);


        retranslateUi(Reclamations);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Reclamations);
    } // setupUi

    void retranslateUi(QWidget *Reclamations)
    {
        Reclamations->setWindowTitle(QApplication::translate("Reclamations", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Reclamations", "\320\240\320\265\320\272\320\273\320\260\320\274\320\260\321\206\321\226\321\227", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Reclamations", "\320\235\320\260 \320\262\320\270\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\275\321\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Reclamations", "\320\235\320\260 \320\277\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\266\320\265\320\275\320\275\321\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Reclamations", "\320\236\321\201\321\202\320\260\321\202\320\276\321\207\320\275\321\226", Q_NULLPTR));
        backButton->setText(QApplication::translate("Reclamations", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Reclamations: public Ui_Reclamations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECLAMATIONS_H
