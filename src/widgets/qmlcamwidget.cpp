#include "qmlcamwidget.h"
#include "ui_qmlcamwidget.h"

QMLCamWidget::QMLCamWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMLCamWidget)
{
    ui->setupUi(this);
}

QMLCamWidget::~QMLCamWidget()
{
    delete ui;
}

void QMLCamWidget::onImageCaptured(const QImage &preview)
{

}
