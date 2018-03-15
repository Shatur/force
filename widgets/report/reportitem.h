#ifndef REPORTITEM_H
#define REPORTITEM_H

#include "backend/api.h"

#include <QWidget>

#include <QLineEdit>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QMap>
#include <QVector>

#include <QKeyEvent>

#include "backend/api.h"

namespace Ui {
class ReportItem;
}

class ReportItem : public QWidget
{
    Q_OBJECT

public:
    explicit ReportItem(int id,
                        const QVector<QString> &staticReportFields,\
                        const QVector<QString> &reportFields,\
                        Fesko::SReportItem *report_item,
                        bool isRO,
                        QWidget *parent);
    ~ReportItem();

public slots:
    void updateData();

private slots:
    void stateChanged(int state);

protected:
    virtual void keyPressEvent(QKeyEvent* e);

private:
    Ui::ReportItem *ui;

    Fesko::SReportItem* item;

    QMap<QString*, QLineEdit*> valuesBinding;

    QMap<QCheckBox*, QLineEdit*> cbToEdit;
    QMap<QLineEdit*, QCheckBox*> editToCb;

    int idPosition = 0;
    bool readOnly = true;
    int sizeRatio;
    int widthParent;
    QFont font;



    Fesko::SReportItem *rpItem;    

    void typeSeven(QLineEdit *edit, int i);

    void setRowName();
    void setRowAttr();
    void setRowEdit();




};

#endif // REPORTITEM_H
