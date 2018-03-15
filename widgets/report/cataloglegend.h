#ifndef CATALOGLEGEND_H
#define CATALOGLEGEND_H

#include <QWidget>

#include "backend/api.h"

namespace Ui {
class CatalogLegend;
}

class CatalogLegend : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogLegend(QWidget *parent = 0);
    ~CatalogLegend();

    void setup(Fesko::SCatalog *cat);

private:
    Ui::CatalogLegend *ui;
};

#endif // CATALOGLEGEND_H
