#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QWidget>

#include "backend/api.h"

namespace Ui {
class Reclamation;
}

class Reclamation : public QWidget
{
    Q_OBJECT

public:
    explicit Reclamation(Fesko::SReclamation& r, QWidget *parent = 0);
    ~Reclamation();

private slots:
    void on_goReportBtn_clicked();

private:
    Ui::Reclamation *ui;
    int report_id;
};

#endif // RECLAMATION_H
