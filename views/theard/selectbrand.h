#ifndef SELECTBRAND_H
#define SELECTBRAND_H

#include <QWidget>
#include <QDate>
#include <QQmlContext>
#include <QQuickItem>

#include "backend/api.h"

#include "viewmanager.h"

namespace Ui {
class SelectBrand;
}

class SelectBrand : public QWidget, public ViewsObserver
{
    Q_OBJECT

public:
    explicit SelectBrand(QWidget *parent = 0);
    ~SelectBrand();

    bool setup(QDate date, int id, bool isRO = false);

    virtual bool onViewPop(QWidget* current, bool isKey);

private:

    Ui::SelectBrand *ui;

    QDate report_date;
    int   shop_id;
    Fesko::TShopReports sr;
    bool isReadOnly;

    QList<QString> model;//for qml
    void shift();//інтеграція qml

protected:
    virtual void	resizeEvent(QResizeEvent * event);

private slots:
    void on_backButton_clicked();
    void on_goReportBtn_clicked();
    void on_emptyReportBtn_clicked();
};

#endif // SELECTBRAND_H
