#ifndef Catalog_H
#define Catalog_H

#include <QAbstractListModel>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


#include "backend/singletonconnect.h"

class Catalog : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Catalog(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) ;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual QHash<int, QByteArray> roleNames() const;

    //_______________________________________________________________________________________________________________

    enum Roles {
        Id = Qt::UserRole + 1,
        GlobalId, Name, StaticFields, ReportFields,ReportTypes
    };
    struct ProductItem
    {//струтура для даних позицій, що мають бути в каталозі
        int localId; //номер в каталозі
        QString globalId; //номер по базі
        QString name;//ім'ячко
        QList<QString> staticFields; //незмінні поля
        QList<QString> reportFieldsString; //поля для звіту
        QList<QString> reportFieldsType; //поля для звіту
    };
    void setReadOnlyFlag(bool);
    void setShopId(int value);
    void setReportId(int value);

    QVariantHash shortReportString();
    bool goodJobFinish();//відповідаю чи готов звіт бути надісланим

    Q_INVOKABLE bool getReadOnlyFlag();
    Q_INVOKABLE bool goodJobDot(int index);
    Q_INVOKABLE void changeCatalogList();
    Q_INVOKABLE QVariant getStackStatus();//верта розмір каталогу і позицію розділу у ньому
    Q_INVOKABLE QVariant getListName();//дає доступним ім'я сиску із qml
    Q_INVOKABLE QVariant getLegendListStatic() const;//надсилає в qml поля легенди
    Q_INVOKABLE QVariant getLegendListReport() const;//надсилає в qml поля легенди
    Q_INVOKABLE QVariant getLegendFirstStatic() const;//надсилає в qml поля легенди
    Q_INVOKABLE void editReportField(int indexRow, int indexField, QString value);//вносе зміни із qml до моделі
private:
    class packman{
    public:
        static QJsonArray staticFieldsToJson(QList<QString> value);
        static QJsonArray reportFieldsToJson(QList<QString> value, QList<QString> type);
        static QJsonObject reportFieldsToJsonShort(QList<ProductItem>, QMap<QString, QString>);
        static QJsonArray itemPack(QJsonValue globalId, QJsonValue name, QJsonArray staticFields, QJsonArray reportFields);
        static QJsonArray valuesListToJsonArray(QList<QJsonValue> list);
        static QJsonArray arraysListToJsonArray(QList<QJsonArray> list);
    };

    void connections();// усі connect() тут. Для ініціалізації.


    void dataExam();//вхідні дані оброблюються тут
    void makePasport(QJsonObject&);//присвоюються дані про катало
    void makeModelList(QJsonArray &);//присвоюються дані до моделі
    void makeLegend(QJsonArray &);//присвоюються дані про легенду
    void rawUpdate();//вносе зміни до пакета відправки

    int catalogIndex;//absolutle. its catalog index
    int catalogsCount = -1;

    bool readOnly = true;
    QString* rawData;//вхідні данні
    QMap<int,QMap<int,bool>>goodJobProgress;
    QMap<int,QList<QString>> legendListStatic;//поля легенди
    QMap<int,QList<QString>> legendListReport;//поля легенди
    QMap<int,QString> legendFirstStatic;//поля легенди
    QMap<int,QMap<QString,QString>> catalogPassport;//personal data of catalog
    QMap<int,QList<ProductItem>> modelData;//головна структура данних моделі


};

#endif // Catalog_H
