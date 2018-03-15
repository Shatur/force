#ifndef ARCHIVMENT_H
#define ARCHIVMENT_H

#include <QWidget>

#include "backend/datatypes.h"

namespace Ui {
class Archivment;
}

class Archivment : public QWidget
{
    Q_OBJECT

public:
    explicit Archivment(Fesko::SArchivment arch, QWidget *parent = 0);
    ~Archivment();

private:
    Ui::Archivment *ui;
};

#endif // ARCHIVMENT_H
