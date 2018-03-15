#ifndef ROUTEITEMWIDGET_H
#define ROUTEITEMWIDGET_H

#include <QWidget>

#include <backend/api.h>

namespace Ui {
class RouteItemWidget;
}

class RouteItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RouteItemWidget(Fesko::SRouteEntry entry, QWidget *parent = 0);
    void  setup(Fesko::SRouteEntry entry);
    ~RouteItemWidget();

private slots:
    void on_doReportBtn_clicked();

private:
    Ui::RouteItemWidget *ui;

    Fesko::SRouteEntry data;

    bool isReadOnly;
};

#endif // ROUTEITEMWIDGET_H
