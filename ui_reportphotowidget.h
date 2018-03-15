/********************************************************************************
** Form generated from reading UI file 'reportphotowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTPHOTOWIDGET_H
#define UI_REPORTPHOTOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <widgets/pixmaplabel.h>

QT_BEGIN_NAMESPACE

class Ui_ReportPhotoWidget
{
public:
    QHBoxLayout *horizontalLayout;
    PixmapLabel *photo;
    QPushButton *removeBtn;

    void setupUi(QWidget *ReportPhotoWidget)
    {
        if (ReportPhotoWidget->objectName().isEmpty())
            ReportPhotoWidget->setObjectName(QStringLiteral("ReportPhotoWidget"));
        ReportPhotoWidget->resize(304, 96);
        ReportPhotoWidget->setMinimumSize(QSize(0, 64));
        horizontalLayout = new QHBoxLayout(ReportPhotoWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        photo = new PixmapLabel(ReportPhotoWidget);
        photo->setObjectName(QStringLiteral("photo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(photo->sizePolicy().hasHeightForWidth());
        photo->setSizePolicy(sizePolicy);
        photo->setSizeIncrement(QSize(0, 0));
        photo->setScaledContents(false);

        horizontalLayout->addWidget(photo);

        removeBtn = new QPushButton(ReportPhotoWidget);
        removeBtn->setObjectName(QStringLiteral("removeBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(removeBtn->sizePolicy().hasHeightForWidth());
        removeBtn->setSizePolicy(sizePolicy1);
        removeBtn->setSizeIncrement(QSize(0, 0));

        horizontalLayout->addWidget(removeBtn);


        retranslateUi(ReportPhotoWidget);

        QMetaObject::connectSlotsByName(ReportPhotoWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportPhotoWidget)
    {
        ReportPhotoWidget->setWindowTitle(QApplication::translate("ReportPhotoWidget", "Form", Q_NULLPTR));
        photo->setText(QApplication::translate("ReportPhotoWidget", "TextLabel", Q_NULLPTR));
        removeBtn->setText(QApplication::translate("ReportPhotoWidget", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportPhotoWidget: public Ui_ReportPhotoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTPHOTOWIDGET_H
