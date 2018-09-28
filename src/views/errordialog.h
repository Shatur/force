#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QWidget>

namespace Ui {
class ErrorDialog;
}

class ErrorDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorDialog(int err, QWidget *parent = 0);
    ~ErrorDialog();

private slots:
    void on_backButton_clicked();

private:
    Ui::ErrorDialog *ui;
};

#define SHOW_ERROR_DIALOG(err)views.push(new ErrorDialog(err,NULL));

#endif // ERRORDIALOG_H
