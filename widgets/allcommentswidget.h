#ifndef ALLCOMMENTSWIDGET_H
#define ALLCOMMENTSWIDGET_H

#include <QWidget>

#include "backend/api.h"
#include "viewmanager.h"
#include "views/report.h"

namespace Ui {
class AllCommentsWidget;
}

class AllCommentsWidget : public QWidget, public ViewsObserver
{
    Q_OBJECT

public:
    explicit AllCommentsWidget(Fesko::SCommentsListEntry data, QWidget *parent = 0);
    ~AllCommentsWidget();

    virtual bool onViewPop(QWidget* current, bool isKey);

private slots:
    void on_goReportBtn_clicked();

private:
    Ui::AllCommentsWidget *ui;

    Fesko::SCommentsListEntry commentEntry;

    Report* reportWgt;

};

#endif // ALLCOMMENTSWIDGET_H
