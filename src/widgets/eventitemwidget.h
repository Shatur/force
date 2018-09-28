#ifndef EVENTITEMWIDGET_H
#define EVENTITEMWIDGET_H

#include <QWidget>

#include "backend/api.h"

namespace Ui {
class EventItemWidget;
}

class EventItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventItemWidget(Fesko::SEvent ev, QWidget *parent = 0);
    ~EventItemWidget();

private:
    Ui::EventItemWidget *ui;
};

#endif // EVENTITEMWIDGET_H
