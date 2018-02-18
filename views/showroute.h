#ifndef SHOWROUTE_H
#define SHOWROUTE_H

#include <QWidget>
#include <QDate>

namespace Ui {
class ShowRoute;
}

class ShowRoute : public QWidget
{
    Q_OBJECT

public:
    explicit ShowRoute(QWidget *parent = 0);
    ~ShowRoute();

    bool setup();

private slots:
    void on_prevDayBtn_clicked();

    void on_newxDayBtn_clicked();

    void on_backButton_clicked();

private:
    Ui::ShowRoute *ui;
    QDate date;

    bool displayData(QDate newDate);
};

#endif // SHOWROUTE_H
