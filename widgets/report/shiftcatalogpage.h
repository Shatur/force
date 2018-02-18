#ifndef SHIFTCATALOGPAGE_H
#define SHIFTCATALOGPAGE_H

#include <QWidget>
#include "mvc/modelcatalog.h"

namespace Ui {
class ShiftCatalogPage;
}

class ShiftCatalogPage : public QWidget
{
    Q_OBJECT

public:
    explicit ShiftCatalogPage(QWidget *parent = 0);
    ~ShiftCatalogPage();    
    void setModel(ModelCatalog*);//модель ініціалізується рівнем вище. Тут передається до qml.    

private:
    ModelCatalog* model;
    Ui::ShiftCatalogPage *ui;
};

#endif // SHIFTCATALOGPAGE_H
