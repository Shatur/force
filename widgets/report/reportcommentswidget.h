#ifndef REPORTCOMMENTSWIDGET_H
#define REPORTCOMMENTSWIDGET_H

#include <QWidget>

#include "backend/api.h"

namespace Ui {
class ReportCommentsWidget;
}

class ReportCommentsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportCommentsWidget(Fesko::SComment comment, QWidget *parent = 0);
    ~ReportCommentsWidget();

private:
    Ui::ReportCommentsWidget *ui;
};

#endif // REPORTCOMMENTSWIDGET_H
