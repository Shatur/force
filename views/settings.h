#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "viewmanager.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget, public ViewsObserver
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    Ui::Settings *ui;
    int fontSize;
    void changeSize();

private slots:
    void on_backBtn_clicked();
    void on_plusBtn_clicked();
    void on_minusBtn_clicked();
    void on_fontSizeEdit_editingFinished();
};

#endif // SETTINGS_H
