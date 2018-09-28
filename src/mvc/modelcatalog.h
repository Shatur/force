#ifndef MODELCATALOG_H
#define MODELCATALOG_H

#include <QAbstractListModel>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


#include "backend/singletonconnect.h"

class ModelCatalog : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ModelCatalog(QObject *parent = nullptr);

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

    struct ProductItems
    {//струтура для даних позицій, що мають бути в каталозі
        int localId; //номер в каталозі
        QString globalId; //номер по базі
        QString name;//ім'ячко
        QList<QString> staticFields; //незмінні поля
        QList<QString> reportFieldsString; //поля для звіту
        QList<QString> reportFieldsType; //поля для звіту
    };
    QList<QString> legendListStatic;//поля легенди
    QList<QString> legendListReport;//поля легенди
    QString legendFirstStatic;//поля легенди


    //QString getRawData();

    Q_INVOKABLE QVariant getLegendListStatic() const;//надсилає в qml поля легенди
    Q_INVOKABLE QVariant getLegendListReport() const;//надсилає в qml поля легенди
    Q_INVOKABLE QVariant getLegendFirstStatic() const;//надсилає в qml поля легенди

    Q_INVOKABLE void editReportField(int indexRow, int indexField, QString value);//вносе зміни із qml до моделі

    void setShopId(int value);

    void setReportId(int value);

    void setCatalogIndex(int value);

    QVariantHash shortReportString();
private:
    class packman{
    public:
        static QJsonArray staticFieldsToJson(QList<QString> value);
        static QJsonArray reportFieldsToJson(QList<QString> value, QList<QString> type);
        static QJsonObject reportFieldsToJsonShort(QList<ProductItems> *,QMap<QString,QString> *);
        static QJsonArray itemPack(QJsonValue globalId, QJsonValue name, QJsonArray staticFields, QJsonArray reportFields);
        static QJsonArray valuesListToJsonArray(QList<QJsonValue> list);
        static QJsonArray arraysListToJsonArray(QList<QJsonArray> list);

    };
    QList<ProductItems> modelData;//головна структура данних моделі

    //QList<QString> headerFields; // поля хідера
    //QList<QString> headerFieldsMask; // маска типів полів до хидера

    void connections();// усі connect() тут. Для ініціалізації.

    QString* rawData;//вхідні данні
    void dataExam();//вхідні дані оброблюються тут
    void makePasport(QJsonObject&);//присвоюються дані про катало
    void makeModel(QJsonArray &);//присвоюються дані до моделі
    void makeLegend(QJsonArray &);//присвоюються дані про легенду
    void rawUpdate();//вносе зміни до пакета відправки

    int catalogIndex;//absolutle. its catalog index
    QMap<QString,QString> catalogPassport;


};

#endif // MODELCATALOG_H
