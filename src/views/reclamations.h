#ifndef RECLAMATIONS_H
#define RECLAMATIONS_H

#include <QWidget>
#include <QListWidget>
#include <QVector>

#include "backend/api.h"

namespace Ui {
class Reclamations;
}

class Reclamations : public QWidget
{
    Q_OBJECT

public:
    explicit Reclamations(QWidget *parent = 0);
    ~Reclamations();

    void setup(Fesko::SReclamations &r);

private slots:
    void on_backButton_clicked();

private:
    Ui::Reclamations *ui;

    void setupList(QListWidget* list, QVector<Fesko::SReclamation> &r);
};

#endif // RECLAMATIONS_H
