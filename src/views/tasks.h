#ifndef TASKS_H
#define TASKS_H

#include <QWidget>

namespace Ui {
class Tasks;
}

class Tasks : public QWidget
{
    Q_OBJECT

public:
    explicit Tasks(QWidget *parent = 0);
    ~Tasks();

    bool setup();

private slots:
    void on_backButton_clicked();

private:
    Ui::Tasks *ui;
};

#endif // TASKS_H
