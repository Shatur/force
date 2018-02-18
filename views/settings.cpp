#include "settings.h"
#include "ui_settings.h"
#include "app_features.h"
#include "backend/sqldataprovider.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    fontSize = Fesko::sql_provider()->fontSize();
    ui->fontSizeEdit->setText(QString::number(fontSize));

    ui->fontSizeEdit->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)"), this));

    changeSize();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::changeSize()
{
    QFont f = ui->exampleLbl->font();
    f.setPixelSize(fontSize);
    ui->exampleLbl->setFont(f);
}

void Settings::on_backBtn_clicked()
{
    Fesko::sql_provider()->cacheFontSize(fontSize);

    views.pop();
}

void Settings::on_plusBtn_clicked()
{
    if ( fontSize < MAX_FONT ) {
        ui->fontSizeEdit->setText(QString::number(++fontSize));
        changeSize();
    }
}

void Settings::on_minusBtn_clicked()
{
    if ( fontSize > MIN_FONT ) {
        ui->fontSizeEdit->setText(QString::number(--fontSize));
        changeSize();
    }
}

void Settings::on_fontSizeEdit_editingFinished()
{
    fontSize = ui->fontSizeEdit->text().toInt();

    if ( fontSize < 8 ) {
        fontSize = 8;
    } else if ( fontSize > 40 ) {
        fontSize = 40;
    }

    ui->fontSizeEdit->setText(QString::number(fontSize));

    changeSize();
}
