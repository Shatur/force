#ifndef REPORT_H
#define REPORT_H

#include "backend/api.h"

#include "views/reportphotos.h"

#include "viewmanager.h"
#include "mvc/modelcatalog.h"

#include <QWidget>

namespace Ui {
class Report;
}

class Report : public QWidget, public ViewsObserver
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    ~Report();

    bool setup(int report_id, int shop_id, bool isReadOnly = false);

    virtual bool onViewPop(QWidget* current, bool isKey);

signals:
    void needUpdate();

private slots:
    void on_toolButton_2_clicked();

    void on_makeReportBtn_clicked();

    void on_makePhotoBtn_clicked();

    void on_catalogSelector_activated(int index);

    void on_addCommentBtn_clicked();

private:
    Ui::Report *ui;

    int id;
    int sid;
    bool is_done;
    bool read_only;
    Fesko::SReport report;

    ReportPhotos* rp;
    QList<ModelCatalog*> listModels;
};

#endif // REPORT_H
