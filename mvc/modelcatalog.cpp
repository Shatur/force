#include "modelcatalog.h"


void ModelCatalog::editReportField(int indexRow,int indexField, QString value)
{
    ProductItem _item;
    _item = modelData.value(catalogIndex).at(indexRow);
    _item.reportFieldsString.replace(indexField, value);
    qDebug()<<_item.reportFieldsString;
    //qDebug()<<value;
    //qDebug()<<modelData.value(catalogIndex)[indexRow].reportFieldsString;
    modelData[catalogIndex].replace(indexRow,_item);
    qDebug()<<modelData.value(catalogIndex)[indexRow].reportFieldsString;
}

ModelCatalog::ModelCatalog(QObject *parent)
    : QAbstractListModel(parent)
{
    rawData = SingletonConnect::getInstance().getReportData();
    dataExam();
    connections();
}

QVariant ModelCatalog::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
    // FIXME: Implement me!
}

bool ModelCatalog::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int ModelCatalog::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())//використовується хак - інверсія умовлення
        return modelData.value(catalogIndex).size();//розмір структури - кількість ітемів у відображенні
}

QVariant ModelCatalog::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case Id:
        return QVariant(modelData.value(catalogIndex).at(index.row()).localId);
    case Name:
        return QVariant(modelData.value(catalogIndex).at(index.row()).name);
    case StaticFields:
        return QVariant(modelData.value(catalogIndex).at(index.row()).staticFields);
    case ReportFields:
        return QVariant(modelData.value(catalogIndex).at(index.row()).reportFieldsString);
    case ReportTypes:
        return QVariant(modelData.value(catalogIndex).at(index.row()).reportFieldsType);
    }

    return QVariant();
}

bool ModelCatalog::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == ReportFields){
        modelData[catalogIndex][index.row()].reportFieldsString = value.toStringList();
     //   emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ModelCatalog::flags(const QModelIndex &index) const
{    
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool ModelCatalog::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool ModelCatalog::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

QHash<int, QByteArray> ModelCatalog::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    if (modelData.isEmpty())
        return roles;

    roles[Id] = "id";
    roles[GlobalId] = "globalId";
    roles[Name] = "name";
    roles[StaticFields] = "staticFields";
    roles[ReportFields] = "reportFields";
    roles[ReportTypes] = "reportTypes";
    return roles;
}

bool ModelCatalog::goodJobDot(int index)
{
    //qDebug()<<index;
   // qDebug()<< modelData[catalogIndex][index].reportFieldsString.contains("");
    return !modelData[catalogIndex][index].reportFieldsString.contains("");//перевірка чи всі поля заповнені для ітему
}

void ModelCatalog::changeCatalogList()
{
    if (catalogsCount<0)
        catalogsCount = catalogIndex;
    if(catalogIndex==catalogsCount)
        catalogIndex = -1;
    catalogIndex++;
}


QVariant ModelCatalog::getLegendListReport() const
{
    return QVariant( legendListReport.value(catalogIndex));
}

QVariant ModelCatalog::getLegendFirstStatic() const
{
    return QVariant(legendFirstStatic.value(catalogIndex));
}

QVariant ModelCatalog::getLegendListStatic() const
{
    return QVariant(legendListStatic.value(catalogIndex));
}

void ModelCatalog::connections()
{
    connect(&SingletonConnect::getInstance(),&SingletonConnect::report,
            [=](QString report){

    });
}

void ModelCatalog::dataExam()
{
    qDebug()<<*rawData;
    if(rawData->isEmpty() or rawData->isNull())
        return;//перевірка на наявність даних

    QJsonDocument jsonDocument = QJsonDocument::fromJson(rawData->toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    QJsonArray jsonArray = jsonObject.value("catalogs").toArray();
    qDebug()<<200<<jsonArray.size();
    int index = jsonArray.size();

    for (int catalogCount =0; catalogCount < jsonArray.size(); catalogCount++){
        qDebug()<<catalogIndex<<333;
        catalogIndex = catalogCount;

        jsonObject = jsonArray.at(catalogIndex).toObject();

        makePasport(jsonObject);//робиться паспорт

        QJsonArray array = jsonObject.value("reportFields").toArray();
        makeLegend(array);//робиться легенда

        array = jsonObject.value("reportItems").toArray();
        makeModelList(array);//робиться модель
    }


    //блок підготовки відповіді від сервера
}

void ModelCatalog::makePasport(QJsonObject &incomingObject)
{
    QMap<QString,QString> _map;
    _map.insert("catalogName",incomingObject["catalogName"].toString());
    catalogPassport.insert(catalogIndex,_map);
    _map.clear();
    _map.insert("id",incomingObject["id"].toString());
    catalogPassport.insert(catalogIndex,_map);

}

void ModelCatalog::makeModelList(QJsonArray &incomingArray)
{
    QList<ProductItem> _list;
    int count = 0;
    foreach (const QJsonValue &item, incomingArray) {
        ProductItem _productItem;
        _productItem.localId = ++count;
        foreach (const QJsonValue subItem, item.toArray()) {
            if(subItem.isString())
                _productItem.globalId = subItem.toString();
            if(subItem.isArray())
            {
                QJsonArray arraySubItem = subItem.toArray();
                if(arraySubItem[1].toString() == "static")
                {
                    _productItem.staticFields.append(arraySubItem[0].toString());
                }
                if(arraySubItem[1].toString() == "report")
                {
                    _productItem.reportFieldsString.append(arraySubItem[0].toString());
                    _productItem.reportFieldsType.append(arraySubItem[2].toString());
                }
            }
        }
        _productItem.name = _productItem.staticFields.first();
        _productItem.staticFields.removeFirst();
        _list.append(_productItem);
        //тут готуються дані для каталогу
    }
    modelData.insert(catalogIndex,_list);
    //надання данним структури у рамках классу
}

void ModelCatalog::makeLegend(QJsonArray &incomingArray)
{
    QList<QString> sttic;
    QList<QString> rprt;

    foreach(const QJsonValue &field, incomingArray){
        if(field.toObject().value("type").toString() == "static")
            sttic.append(field.toObject().value("name").toString());
        else
            rprt.append(field.toObject().value("name").toString());
    }
    legendFirstStatic.insert(catalogIndex,sttic.first());
    sttic.removeFirst();

    legendListStatic.insert(catalogIndex,sttic);

    legendListReport.insert(catalogIndex, rprt);

    qDebug()<<legendListStatic;
    qDebug()<<legendFirstStatic;
    qDebug()<<legendListReport;
    //тут готуються дані для легенди
}

QVariantHash ModelCatalog::shortReportString()
{
    return packman::reportFieldsToJsonShort(modelData.value(catalogIndex), catalogPassport.value(catalogIndex)).toVariantHash();
}

void ModelCatalog::rawUpdate()
{
    QJsonArray rootArray;
    QJsonValue _globalId;
    QJsonValue _name;
    QJsonArray _reportFields;
    QJsonArray _staticFields;
}

QJsonArray ModelCatalog::packman::staticFieldsToJson(QList<QString> value)
{
    QJsonArray rootArray;
    for (const QString & item : value)
    {
        QJsonArray itemArray;
        itemArray.append(item);
        itemArray.append("static");
        rootArray.append(itemArray);
    }
    return rootArray;
    //запаковує статичні дані до json
}

QJsonArray ModelCatalog::packman::reportFieldsToJson(QList<QString> value, QList<QString> type)
{
    QJsonArray rootArray;
    for (int count = 0; count < value.size();count++)
    {
        QJsonArray itemArray;
        itemArray.append(value.at(count));
        itemArray.append("report");
        itemArray.append(type.at(count));

        rootArray.append(itemArray);
    }
    return rootArray;
    //запаковує репорт дані до json
}

QJsonObject ModelCatalog::packman::reportFieldsToJsonShort(QList<ProductItem> list, QMap<QString,QString> passport)
{
    QJsonObject rootObject;
    QJsonArray reportArray;

    rootObject["id"] = passport.value("id").toInt();
    for(int count = 0; count < list.size(); count++)
    {
        QJsonArray reportLine;
        reportLine.append(list.at(count).globalId);
        foreach ( const QString &field, list.at(count).reportFieldsString) {
            reportLine.append(field);
        }
        reportArray.append(reportLine);
    }
    rootObject["items"] = reportArray;
    return rootObject;
}

QJsonArray ModelCatalog::packman::itemPack(QJsonValue globalId, QJsonValue name, QJsonArray staticFields, QJsonArray reportFields)
{
    QJsonArray rootArray;
    QList<QJsonValue> list;
    list.append(name);//пакує ім'я
    list.append(QJsonValue("static"));//пакує ім'я
    staticFields.prepend(packman::valuesListToJsonArray(list));//пакує ім'я

    QList<QJsonArray> arraysList;//пакуються статік і репорт до одно масиву
    arraysList.append(staticFields);//пакуються статік і репорт до одно масиву
    arraysList.append(reportFields);//пакуються статік і репорт до одно масиву
    rootArray = arraysListToJsonArray(arraysList);//пакуються статік і репорт до одно масиву

    rootArray.prepend(globalId);//додається глобальний індекс товару
    return rootArray;
}

QJsonArray ModelCatalog::packman::valuesListToJsonArray(QList<QJsonValue> list)
{
    if(list.isEmpty())
        return QJsonArray();
    QJsonArray array;
    for (auto & value : list)
        array.append(value);
    return array;
    //формує масив із списку значень
}

QJsonArray ModelCatalog::packman::arraysListToJsonArray(QList<QJsonArray> list)
{
    if(list.isEmpty())
        return QJsonArray();

    QJsonArray rootArray;
    for (auto & array : list)
        foreach (QJsonValue value, array) {
            rootArray.append(value);
        }
    return rootArray;
    //формує масив із списку подмасивів
}

