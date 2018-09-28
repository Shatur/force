#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>

#include "backend/api.h"

namespace Ui {
class Events;
}

class Events : public QWidget
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = 0);
    ~Events();

    bool setup();

    virtual void resizeEvent(QResizeEvent *event);

private:
    Ui::Events *ui;

    Fesko::TEvents ev_space;
    Fesko::TEvents ev_action;
    Fesko::TEvents ev_target_task;

private slots:
    void resizeItems();
    void on_backButton_clicked();
};

#endif // EVENTS_H
