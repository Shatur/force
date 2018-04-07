#ifndef SHIFTCATALOGPAGE_H
#define SHIFTCATALOGPAGE_H
#include <QQmlContext>
#include <QQuickItem>

#include <QWidget>
#include "mvc/catalog.h"
#include "mvc/comment.h"
#include "mvc/setting.h"

namespace Ui {
class ShiftCatalogPage;
}

class ShiftCatalogPage : public QWidget
{
    Q_OBJECT
public:
    explicit ShiftCatalogPage(QWidget *parent = 0);
    ~ShiftCatalogPage();    
    void setCatalog(Catalog*);//модель ініціалізується рівнем вище. Тут передається до qml.
    void setComment(Comment*);

public slots:
        void cppSlot(QString);
private:
    Ui::ShiftCatalogPage *ui;
    QQuickItem *root;
    Setting* setting;
signals:
    void toComment(QString);
    void toAction(QString);
};

#endif // SHIFTCATALOGPAGE_H
