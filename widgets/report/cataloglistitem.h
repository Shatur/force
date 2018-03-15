#ifndef CATALOGLISTITEM_H
#define CATALOGLISTITEM_H

#include <QWidget>

namespace Ui {
class CatalogListItem;
}

class CatalogListItem : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogListItem(QString name, QString rules, bool isRO, QWidget *parent = 0);
    ~CatalogListItem();

private:
    Ui::CatalogListItem *ui;
};

#endif // CATALOGLISTITEM_H
