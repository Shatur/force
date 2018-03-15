/********************************************************************************
** Form generated from reading UI file 'reportphotos.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTPHOTOS_H
#define UI_REPORTPHOTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportPhotos
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *photosList;
    QPushButton *addPhotoBtn;
    QFrame *bottom_frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *backButton;

    void setupUi(QWidget *ReportPhotos)
    {
        if (ReportPhotos->objectName().isEmpty())
            ReportPhotos->setObjectName(QStringLiteral("ReportPhotos"));
        ReportPhotos->resize(400, 442);
        verticalLayout = new QVBoxLayout(ReportPhotos);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ReportPhotos);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
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

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame);

        frame_3 = new QFrame(ReportPhotos);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        photosList = new QListWidget(frame_3);
        photosList->setObjectName(QStringLiteral("photosList"));

        verticalLayout_2->addWidget(photosList);

        addPhotoBtn = new QPushButton(frame_3);
        addPhotoBtn->setObjectName(QStringLiteral("addPhotoBtn"));

        verticalLayout_2->addWidget(addPhotoBtn);


        verticalLayout->addWidget(frame_3);

        bottom_frame = new QFrame(ReportPhotos);
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
        backButton->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(backButton);


        verticalLayout->addWidget(bottom_frame);


        retranslateUi(ReportPhotos);

        QMetaObject::connectSlotsByName(ReportPhotos);
    } // setupUi

    void retranslateUi(QWidget *ReportPhotos)
    {
        ReportPhotos->setWindowTitle(QApplication::translate("ReportPhotos", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ReportPhotos", "\320\244\320\276\321\202\320\276\320\263\321\200\320\260\321\204\321\226\321\227 \320\264\320\276 \320\267\320\262\321\226\321\202\321\203", Q_NULLPTR));
        addPhotoBtn->setText(QApplication::translate("ReportPhotos", "\320\224\320\276\320\264\320\260\321\202\320\270 \321\204\320\276\321\202\320\276", Q_NULLPTR));
        backButton->setText(QApplication::translate("ReportPhotos", "\320\235\320\260\320\267\320\260\320\264 \320\264\320\276 \320\267\320\262\321\226\321\202\321\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportPhotos: public Ui_ReportPhotos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTPHOTOS_H
