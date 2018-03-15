#ifndef CATALOGPAGE_H
#define CATALOGPAGE_H

#include <QWidget>

#include "backend/api.h"


namespace Ui {
class CatalogPage;
}

class CatalogPage : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogPage(int id,Fesko::SCatalog *cat, bool isRO = false, QWidget *parent = 0);
    ~CatalogPage();

    void update();

signals:
    void needUpdate();

public slots:
    void dataUpdate();

private:
    Ui::CatalogPage *ui;
};

#endif // CATALOGPAGE_H
