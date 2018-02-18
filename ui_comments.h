/********************************************************************************
** Form generated from reading UI file 'comments.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTS_H
#define UI_COMMENTS_H

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

class Ui_Comments
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *topFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QListWidget *commentsList;
    QFrame *bottom_frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *backButton;

    void setupUi(QWidget *Comments)
    {
        if (Comments->objectName().isEmpty())
            Comments->setObjectName(QStringLiteral("Comments"));
        Comments->resize(450, 600);
        verticalLayout = new QVBoxLayout(Comments);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topFrame = new QFrame(Comments);
        topFrame->setObjectName(QStringLiteral("topFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(topFrame->sizePolicy().hasHeightForWidth());
        topFrame->setSizePolicy(sizePolicy);
        topFrame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(topFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(topFrame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(topFrame);

        commentsList = new QListWidget(Comments);
        commentsList->setObjectName(QStringLiteral("commentsList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(80);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(commentsList->sizePolicy().hasHeightForWidth());
        commentsList->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(commentsList);

        bottom_frame = new QFrame(Comments);
        bottom_frame->setObjectName(QStringLiteral("bottom_frame"));
        sizePolicy.setHeightForWidth(bottom_frame->sizePolicy().hasHeightForWidth());
        bottom_frame->setSizePolicy(sizePolicy);
        bottom_frame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        bottom_frame->setFrameShape(QFrame::StyledPanel);
        bottom_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(bottom_frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QToolButton(bottom_frame);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(backButton);


        verticalLayout->addWidget(bottom_frame);


        retranslateUi(Comments);

        QMetaObject::connectSlotsByName(Comments);
    } // setupUi

    void retranslateUi(QWidget *Comments)
    {
        Comments->setWindowTitle(QApplication::translate("Comments", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Comments", "\320\232\320\276\320\274\320\265\320\275\321\202\320\260\321\200\321\226", Q_NULLPTR));
        backButton->setText(QApplication::translate("Comments", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Comments: public Ui_Comments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTS_H
