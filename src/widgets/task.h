#ifndef TASK_H
#define TASK_H

#include <QWidget>

#include "backend/datatypes.h"

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(Fesko::STask task, QWidget *parent = 0);
    ~Task();

private slots:
    void on_goReportBtn_clicked();

private:
    Ui::Task *ui;
    Fesko::STask myTask;
    int reportID;
};

#endif // TASK_H
