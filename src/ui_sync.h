/********************************************************************************
** Form generated from reading UI file 'sync.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNC_H
#define UI_SYNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <widgets/pixmaplabel.h>

QT_BEGIN_NAMESPACE

class Ui_Sync
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    PixmapLabel *syncImage;
    QLabel *syncText;
    QSpacerItem *verticalSpacer_7;
    QLabel *commonLabel;
    QProgressBar *commonProgress;
    QLabel *currentLabel;
    QProgressBar *currentProgress;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *Sync)
    {
        if (Sync->objectName().isEmpty())
            Sync->setObjectName(QStringLiteral("Sync"));
        Sync->resize(324, 398);
        verticalLayout = new QVBoxLayout(Sync);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        syncImage = new PixmapLabel(Sync);
        syncImage->setObjectName(QStringLiteral("syncImage"));
        syncImage->setPixmap(QPixmap(QString::fromUtf8(":/pics/uploading.png")));
        syncImage->setScaledContents(true);
        syncImage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(syncImage);

        syncText = new QLabel(Sync);
        syncText->setObjectName(QStringLiteral("syncText"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        syncText->setFont(font);
        syncText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(syncText);

        verticalSpacer_7 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        commonLabel = new QLabel(Sync);
        commonLabel->setObjectName(QStringLiteral("commonLabel"));

        verticalLayout->addWidget(commonLabel);

        commonProgress = new QProgressBar(Sync);
        commonProgress->setObjectName(QStringLiteral("commonProgress"));
        commonProgress->setValue(0);

        verticalLayout->addWidget(commonProgress);

        currentLabel = new QLabel(Sync);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));

        verticalLayout->addWidget(currentLabel);

        currentProgress = new QProgressBar(Sync);
        currentProgress->setObjectName(QStringLiteral("currentProgress"));
        currentProgress->setValue(0);

        verticalLayout->addWidget(currentProgress);

        verticalSpacer_6 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);


        retranslateUi(Sync);

        QMetaObject::connectSlotsByName(Sync);
    } // setupUi

    void retranslateUi(QWidget *Sync)
    {
        Sync->setWindowTitle(QApplication::translate("Sync", "Form", Q_NULLPTR));
        syncImage->setText(QString());
        syncText->setText(QApplication::translate("Sync", "\320\227\320\260\320\277\321\203\321\201\320\272 \321\201\320\270\320\275\321\205\321\200\320\276\320\275\321\226\320\267\320\260\321\206\321\226\321\227...", Q_NULLPTR));
        commonLabel->setText(QString());
        currentLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sync: public Ui_Sync {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNC_H
