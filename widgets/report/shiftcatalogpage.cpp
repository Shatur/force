#include "shiftcatalogpage.h"
#include "ui_shiftcatalogpage.h"
#include <QQmlContext>



ShiftCatalogPage::ShiftCatalogPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShiftCatalogPage)
{
    ui->setupUi(this);
    ui->quickWidget;
}

ShiftCatalogPage::~ShiftCatalogPage()
{
    delete ui;
}

void ShiftCatalogPage::setModel(ModelCatalog *_m)
{
    model = _m;
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->quickWidget->rootContext()->setContextProperty("modelCatalog", model);//модель ініціалізується в батька. тут віддається до qml.
    ui->quickWidget->setSource(QUrl("qrc:/ui/qml/Catalog/CatalogView.qml"));//тека з файлами цьго уі
}
