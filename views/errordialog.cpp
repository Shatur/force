#include "errordialog.h"
#include "ui_errordialog.h"

#include "backend/api.h"
#include "viewmanager.h"

ErrorDialog::ErrorDialog(int err, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);

    ui->errorTextLbl->setText(Fesko::errorToString(err));
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::on_backButton_clicked()
{
    views.pop();
}

