/********************************************************************************
** Form generated from reading UI file 'report.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_H
#define UI_REPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Report
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *top_frame;
    QHBoxLayout *horizontalLayout;
    QComboBox *catalogSelector;
    QStackedWidget *stack;
    QWidget *MessagePage;
    QVBoxLayout *verticalLayout_2;
    QListWidget *commentsList;
    QTextEdit *commentEdit;
    QPushButton *addCommentBtn;
    QFrame *bottom_frame;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_2;
    QToolButton *makePhotoBtn;
    QToolButton *makeReportBtn;

    void setupUi(QWidget *Report)
    {
        if (Report->objectName().isEmpty())
            Report->setObjectName(QStringLiteral("Report"));
        Report->resize(400, 600);
        verticalLayout = new QVBoxLayout(Report);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        top_frame = new QFrame(Report);
        top_frame->setObjectName(QStringLiteral("top_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setStyleSheet(QStringLiteral("top_frame: {background-color: rgb(0, 0, 127);}"));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(top_frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        catalogSelector = new QComboBox(top_frame);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/original/comment_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        catalogSelector->addItem(icon, QString());
        catalogSelector->setObjectName(QStringLiteral("catalogSelector"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(catalogSelector->sizePolicy().hasHeightForWidth());
        catalogSelector->setSizePolicy(sizePolicy1);
        catalogSelector->setStyleSheet(QLatin1String("QListView#comboListView {\n"
"    background: rgb(80, 80, 80);\n"
"    color: rgb(220, 220, 220);\n"
"    min-height: 90px;\n"
"    margin: 0 0 0 0;\n"
"}\n"
"QComboBox QAbstractItemViewItem {\n"
"	min-height: 90px;\n"
"    background-color: rgb(255, 255, 255);\n"
"}\n"
"background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));
        catalogSelector->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(catalogSelector);


        verticalLayout->addWidget(top_frame);

        stack = new QStackedWidget(Report);
        stack->setObjectName(QStringLiteral("stack"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(80);
        sizePolicy2.setHeightForWidth(stack->sizePolicy().hasHeightForWidth());
        stack->setSizePolicy(sizePolicy2);
        MessagePage = new QWidget();
        MessagePage->setObjectName(QStringLiteral("MessagePage"));
        verticalLayout_2 = new QVBoxLayout(MessagePage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        commentsList = new QListWidget(MessagePage);
        commentsList->setObjectName(QStringLiteral("commentsList"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(80);
        sizePolicy3.setHeightForWidth(commentsList->sizePolicy().hasHeightForWidth());
        commentsList->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(commentsList);

        commentEdit = new QTextEdit(MessagePage);
        commentEdit->setObjectName(QStringLiteral("commentEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(20);
        sizePolicy4.setHeightForWidth(commentEdit->sizePolicy().hasHeightForWidth());
        commentEdit->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(commentEdit);

        addCommentBtn = new QPushButton(MessagePage);
        addCommentBtn->setObjectName(QStringLiteral("addCommentBtn"));

        verticalLayout_2->addWidget(addCommentBtn);

        stack->addWidget(MessagePage);

        verticalLayout->addWidget(stack);

        bottom_frame = new QFrame(Report);
        bottom_frame->setObjectName(QStringLiteral("bottom_frame"));
        sizePolicy.setHeightForWidth(bottom_frame->sizePolicy().hasHeightForWidth());
        bottom_frame->setSizePolicy(sizePolicy);
        bottom_frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        bottom_frame->setFrameShape(QFrame::StyledPanel);
        bottom_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(bottom_frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_2 = new QToolButton(bottom_frame);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(toolButton_2);

        makePhotoBtn = new QToolButton(bottom_frame);
        makePhotoBtn->setObjectName(QStringLiteral("makePhotoBtn"));
        sizePolicy1.setHeightForWidth(makePhotoBtn->sizePolicy().hasHeightForWidth());
        makePhotoBtn->setSizePolicy(sizePolicy1);
        makePhotoBtn->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(makePhotoBtn);

        makeReportBtn = new QToolButton(bottom_frame);
        makeReportBtn->setObjectName(QStringLiteral("makeReportBtn"));
        sizePolicy1.setHeightForWidth(makeReportBtn->sizePolicy().hasHeightForWidth());
        makeReportBtn->setSizePolicy(sizePolicy1);
        makeReportBtn->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(makeReportBtn);


        verticalLayout->addWidget(bottom_frame);


        retranslateUi(Report);

        QMetaObject::connectSlotsByName(Report);
    } // setupUi

    void retranslateUi(QWidget *Report)
    {
        Report->setWindowTitle(QApplication::translate("Report", "Form", Q_NULLPTR));
        catalogSelector->setItemText(0, QApplication::translate("Report", "\320\237\320\276\320\262\321\226\320\264\320\276\320\274\320\273\320\265\320\275\320\275\321\217", Q_NULLPTR));

        addCommentBtn->setText(QApplication::translate("Report", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\272\320\276\320\274\320\265\320\275\321\202\320\260\321\200", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("Report", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        makePhotoBtn->setText(QApplication::translate("Report", "\320\227\321\200\320\276\320\261\320\270\321\202\320\270 \321\204\320\276\321\202\320\276", Q_NULLPTR));
        makeReportBtn->setText(QApplication::translate("Report", "\320\227\320\264\320\260\321\202\320\270 \320\267\320\262\321\226\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Report: public Ui_Report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_H
