#ifndef SYNC_H
#define SYNC_H

#include <QWidget>
#include "viewmanager.h"

namespace Ui {
class Sync;
}

class Sync : public QWidget
{
    Q_OBJECT

public:
    explicit Sync(QWidget *parent = 0);
    ~Sync();

    int doSync();

private:
    Ui::Sync *ui;

    int upload();
    int download();

};

#endif // SYNC_H
