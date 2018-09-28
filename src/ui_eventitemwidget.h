/********************************************************************************
** Form generated from reading UI file 'eventitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTITEMWIDGET_H
#define UI_EVENTITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventItemWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *startDateLbl;
    QLabel *label_2;
    QLabel *endDateLbl;
    QLabel *label_3;
    QLabel *clientLbl;
    QLabel *nameLbl;
    QLabel *descriptionLbl;
    QFrame *line;

    void setupUi(QWidget *EventItemWidget)
    {
        if (EventItemWidget->objectName().isEmpty())
            EventItemWidget->setObjectName(QStringLiteral("EventItemWidget"));
        EventItemWidget->resize(228, 395);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventItemWidget->sizePolicy().hasHeightForWidth());
        EventItemWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(EventItemWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(EventItemWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        startDateLbl = new QLabel(EventItemWidget);
        startDateLbl->setObjectName(QStringLiteral("startDateLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, startDateLbl);

        label_2 = new QLabel(EventItemWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        endDateLbl = new QLabel(EventItemWidget);
        endDateLbl->setObjectName(QStringLiteral("endDateLbl"));

        formLayout->setWidget(1, QFormLayout::FieldRole, endDateLbl);

        label_3 = new QLabel(EventItemWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        clientLbl = new QLabel(EventItemWidget);
        clientLbl->setObjectName(QStringLiteral("clientLbl"));

        formLayout->setWidget(2, QFormLayout::FieldRole, clientLbl);


        verticalLayout->addLayout(formLayout);

        nameLbl = new QLabel(EventItemWidget);
        nameLbl->setObjectName(QStringLiteral("nameLbl"));
        nameLbl->setFont(font);
        nameLbl->setWordWrap(true);

        verticalLayout->addWidget(nameLbl);

        descriptionLbl = new QLabel(EventItemWidget);
        descriptionLbl->setObjectName(QStringLiteral("descriptionLbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(descriptionLbl->sizePolicy().hasHeightForWidth());
        descriptionLbl->setSizePolicy(sizePolicy1);
        descriptionLbl->setMaximumSize(QSize(200, 16777215));
        descriptionLbl->setTextFormat(Qt::AutoText);
        descriptionLbl->setWordWrap(true);

        verticalLayout->addWidget(descriptionLbl);

        line = new QFrame(EventItemWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(EventItemWidget);

        QMetaObject::connectSlotsByName(EventItemWidget);
    } // setupUi

    void retranslateUi(QWidget *EventItemWidget)
    {
        EventItemWidget->setWindowTitle(QApplication::translate("EventItemWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("EventItemWidget", "\320\237\320\276\321\207\320\260\321\202\320\276\320\272:", Q_NULLPTR));
        startDateLbl->setText(QApplication::translate("EventItemWidget", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("EventItemWidget", "\320\232\321\226\320\275\320\265\321\206\321\214:", Q_NULLPTR));
        endDateLbl->setText(QApplication::translate("EventItemWidget", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("EventItemWidget", "\320\232\320\273\321\226\321\224\320\275\321\202:", Q_NULLPTR));
        clientLbl->setText(QApplication::translate("EventItemWidget", "TextLabel", Q_NULLPTR));
        nameLbl->setText(QApplication::translate("EventItemWidget", "TextLabel", Q_NULLPTR));
        descriptionLbl->setText(QApplication::translate("EventItemWidget", "\"\320\240\321\203\320\272\320\260\320\262\320\270\321\207\320\272\320\260 \321\201 01.05-14.05 \320\275\320\260 \320\235\320\241 1\320\273 \342\200\242\\t\320\236\320\261\320\276\320\262\321\217\320\267\320\272\320\276\320\262\320\276 \320\275\320\260\321\217\320\262\320\275\321\226\321\201\321\202\321\214 \320\260\320\272\321\206\321\226\320\271\320\275\320\276\320\263\320\276 \321\206\321\226\320\275\320\275\320\270\320\272\320\260 \320\264\320\273\321\217 \320\272\320\276\320\266\320\275\320\276\320\263\320\276 \320\262\320\270\320\264\321\203 \321\202\320\260 \320\277\321\226\320\264\320\273\320\276\320\266\320\272\320\270 \302\253\320\220\320\272\321\206\321\226\321\217\302\273 \320\267 \321\206\321\226\320\275\320\275\320\270\320\272\320\276\320\274 \320\275\320\260 \320\236\320\234\320\237 \321\226 \320\224\320\234\320\237\n"
"\342\200\242\\t\320\235\320\260 \321\207\320\260\321\201 \320\260\320\272\321\206\321\226\321\227 \321\203 \320\274\320\260\320\263\320\260\320\267\320\270\320\275\320\260\321\205"
                        " \320\277\320\265\321\200\320\265\320\264\320\261\320\260\321\207\320\265\320\275\320\260 \320\264\320\276\320\264\320\260\321\202\320\272\320\276\320\262\320\260 \320\262\320\270\320\272\320\273\320\260\320\264\320\272\320\260 \320\275\320\260 \320\224\320\234\320\237 \342\200\223 \321\202\320\276\321\200\321\206\321\226, \321\201\321\202\320\265\320\273\320\260\320\266\321\226, \320\275\320\260\320\277\320\276\320\273\321\214\320\275\320\260 \321\207\320\270 \320\277\321\226\320\264\320\264\320\276\320\275\320\276\320\274\321\226\321\201\321\206\320\265. \320\235\320\260 \320\274\321\226\321\201\321\206\321\226 \320\262 \320\233\320\237\320\240 \320\276\320\261\320\276\320\262\321\217\320\267\320\272\320\276\320\262\320\276 \320\262\320\270\321\217\321\201\320\275\321\217\321\202\320\270 \320\267\320\260 \320\224\320\234\320\237 \321\202\320\260 \321\201\320\277\320\276\321\201\321\226\320\261 \321\200\320\276\320\267\320\274\321\226\321\211\320\265\320\275\320\275\321\217. \320\243 \320\262\320\270\320\277\320"
                        "\260\320\264\320\272\321\203 \320\275\320\260\320\277\320\276\320\273\321\214\320\275\320\276\321\227 \321\207\320\270 \320\262\320\270\320\272\320\273\320\260\320\264\320\272\320\270 \320\275\320\260 \320\277\321\226\320\264\320\264\320\276\320\275\321\226 \320\262\321\201\321\226 \321\217\321\211\320\270\320\272\320\270 \320\262\321\201\320\272\321\200\320\270\320\262\320\260\321\202\320\270, \321\211\320\276\320\261 \320\277\321\200\320\276\320\264\321\203\320\272\321\206\321\226\321\217 \320\261\321\203\320\273\320\260 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\320\260. \320\240\320\276\320\267\320\264\321\200\321\203\320\272\320\276\320\262\321\203\320\262\320\260\321\202\320\270 \321\202\320\260 \321\200\320\276\320\267\320\274\321\226\321\211\321\203\320\262\320\260\321\202\320\270 \320\260\320\272\321\206\321\226\320\271\320\275\321\226 \321\206\321\226\320\275\320\275\320\270\320\272\320\270 \321\202\320\260 \320\2204. \n"
"\342\200\242\\t\320\232\320\276\320\275\321\202\321\200\320\276\320"
                        "\273\321\216\320\262\320\260\321\202\320\270 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\321\203 \320\262\321\201\321\226\321\205 \320\274\321\226\321\201\321\206\321\214 \320\277\321\200\320\276\320\264\320\260\320\266\321\203 \320\236\320\234\320\237, \320\224\320\234\320\237 \321\202\320\260 \320\267\320\260\320\273\320\270\321\210\320\272\320\270 \320\277\321\200\320\276\321\202\321\217\320\263\320\276\320\274 \320\262\321\201\321\226\321\224\321\227 \320\260\320\272\321\206\321\226\321\227. \320\237\321\200\320\270 \320\262\321\226\320\264\321\201\321\202\321\203\320\275\320\276\321\201\321\202\321\226 \321\207\320\270 \320\272\321\200\320\270\321\202\320\270\321\207\320\275\320\270\321\205  \320\267\320\260\320\273\320\270\321\210\320\272\320\260\321\205 \320\276\320\261\320\276\320\262\321\217\320\267\320\272\320\276\320\262\320\276 \321\226\320\275\321\204\320\276\321\200\320\274\321\203\320\262\320\260\321\202\320\270 \320\233\320\237\320\240 \321\202\320\260 \320\275\320\260\320\277\320\276"
                        "\320\273\321\217\320\263\320\260\321\202\320\270 \320\275\320\260 \320\264\320\276\320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\226. (\320\237\321\200\320\276\320\264\321\203\320\272\321\206\321\226\321\217 \320\267\320\260\320\262\320\265\320\267\320\265\320\275\320\260 \320\275\320\260 \320\240\320\246 \321\203 \320\264\320\276\321\201\321\202\320\260\321\202\320\275\321\226\321\205 \320\276\320\261\321\201\321\217\320\263\320\260\321\205).", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EventItemWidget: public Ui_EventItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTITEMWIDGET_H
