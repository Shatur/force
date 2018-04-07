#include "shiftcatalogpage.h"
#include "ui_shiftcatalogpage.h"

ShiftCatalogPage::ShiftCatalogPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShiftCatalogPage)
{
    ui->setupUi(this);
    setting = new Setting;
    ui->quickWidget->rootContext()->setContextProperty("Setting",setting);//додається модель налаштувань
    ui->quickWidget->rootContext()->setContextProperty("Controller", this);//зв'язаний з qml контролер
}

void ShiftCatalogPage::cppSlot(QString v)
{
    if(v.contains("Comment"))
        emit toComment(v);

    if(v.contains("Action"))
        emit toAction(v);
}

ShiftCatalogPage::~ShiftCatalogPage()
{
    setting->deleteLater();
    delete ui;
}

void ShiftCatalogPage::setComment(Comment *_m)
{
    ui->quickWidget->rootContext()->setContextProperty("Comment", _m);//модель ініціалізується в батька. тут віддається до qml.
    ui->quickWidget->setSource(QUrl("qrc:/ui/qml/Catalog/CatalogView.qml"));//тека з файлами цьго уі
    root = ui->quickWidget->rootObject();
    QObject::connect(root, SIGNAL(qmlSignal(QString)),this, SLOT(cppSlot(QString)));
}

void ShiftCatalogPage::setCatalog(Catalog *_m)
{
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->quickWidget->rootContext()->setContextProperty("Catalog", _m);//модель ініціалізується в батька. тут віддається до qml.
}
