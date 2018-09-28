#include "jsondata.h"

#include <QJsonObject>
#include <QJsonArray>

#define JSON_FIELD(object, json_field, var)\
    if (object.contains(json_field)) var = object[json_field]

#define JSON_FIELD_REQIRED(object, json_field, var)\
    if (!object.contains(json_field)) { return ERR_PROTOCOL;}\
        else var = object[json_field]\

#define JSON_ARRAY(object, array_obj, name)\
    if (!object.contains(name)){return ERR_PROTOCOL;}\
    if (!object[name].isArray()) { return ERR_PROTOCOL;}\
    QJsonArray array_obj = object[name].toArray();


int Fesko::fromJSON(QJsonObject resp, Fesko::SReport &out)
{
    QJsonObject report;
    QString tmp;

    //Get common report attributes

    report = resp["report"].toObject();
    JSON_FIELD_REQIRED(report, "id", out.id).toString().toInt();
    JSON_FIELD_REQIRED(report, "date", tmp).toString();
    out.date = QDate::fromString(tmp, "yyyy-MM-dd");
    JSON_FIELD(report, "client", out.client).toString();
    JSON_FIELD(report, "clienttn", out.clienttn).toString();
    JSON_FIELD(report, "clientid", out.clientid).toString().toInt();
    JSON_FIELD(report, "shop", out.shop).toString();
    JSON_FIELD(report, "city", out.city).toString();
    JSON_FIELD(report, "cityid", out.cityid).toString().toInt();
    JSON_FIELD(report, "address", out.address).toString();
    JSON_FIELD(report, "shopid", out.shopid).toString().toInt();
    JSON_FIELD(report, "sp_width", out.longtitude).toString().toDouble();
    JSON_FIELD(report, "sp_height", out.latitude).toString().toDouble();
    JSON_FIELD(report, "mr", out.mr).toString();
    JSON_FIELD(report, "sv", out.sv).toString();
    JSON_FIELD(report, "status", out.status).toString().toInt();

    //iterate catalogs ...

    JSON_ARRAY(resp, catalogs, "catalogs");
    out.catalogs.clear();
    for(int i=0; i<catalogs.size(); i++)
    {
        QJsonObject jcatalog = catalogs[i].toObject();
        SCatalog catalog;
        JSON_FIELD_REQIRED(jcatalog, "id", catalog.id).toString().toInt();
        JSON_FIELD(jcatalog, "catalogName", catalog.catalogName).toString();
        JSON_FIELD(jcatalog, "catalogRule", catalog.catalogRule).toString();

        //iterate reportFields

        JSON_ARRAY(jcatalog, rf, "reportFields");
        for(int j=0; j<rf.size(); j++)
        {
            QJsonObject jfield = rf[j].toObject();;
            QString name, type;
            JSON_FIELD_REQIRED(jfield, "name", name).toString();
            JSON_FIELD_REQIRED(jfield, "type", type).toString();
            if (type.trimmed().toLower() == "report")
            {
                catalog.reportFields.push_back(name);
            }
            else
            {
                catalog.staticReportFields.push_back(name);
            }
        }//all reportFields array

        JSON_ARRAY(jcatalog, reportItems, "reportItems");
        int err = fromJSON(reportItems, catalog.reportItems);
        if (NO_ERROR != err)
        {
            return err;
        }
        out.catalogs.push_back(catalog);

    }//for all catalogs
    return NO_ERROR;
}

int Fesko::fromJSON(QJsonArray reportItems, QVector<Fesko::SReportItem> &items)
{
    items.clear();
    for(int j=0; j<reportItems.size(); j++)
    {
        QJsonArray ri = reportItems[j].toArray();
        if (ri.size()<1) return ERR_PROTOCOL;
        SReportItem item;
        item.id = ri[0].toString().toInt();
        for (int k=1; k<ri.size(); k++)
        {
            if (!ri[k].isArray()) return ERR_PROTOCOL;
            QJsonArray val = ri[k].toArray();
            if (val.size()<2) return ERR_PROTOCOL;
            QString value = val[0].toString();
            QString type = val[1].toString();
            if (type.trimmed().toLower() == "report")
            {
                SReportItemValue val_item;
                int itype = 0;
                val_item.value = value;
                if (val.size()>2) itype = val[2].toString().toInt();
                val_item.type = itype;
                item.reportValues.push_back(val_item);
            }
            else
            {
                item.staticValues.push_back(value);
            }
        }
        items.push_back(item);
    }

    return NO_ERROR;

}

int Fesko::mergeJSON(QJsonArray arr, Fesko::SReport &report)
{
    for(int i=0; i<arr.size(); i++)
    {
        //get catalog
        QJsonObject cat = arr[0].toObject();
        if (!cat.contains("id"))
            continue;
        int cat_id = cat["id"].toInt();

        //find catalog by id in report
        int rcat_id = -1;
        for(int i=0; i<report.catalogs.size(); i++)
        {
            if (report.catalogs[i].id == cat_id)
            {
                rcat_id = i; break;
            }
        }
        if (rcat_id<0) continue; //not found

        QVector<Fesko::SReportItem> items;

        if (!cat.contains("items")) continue;
        if (!cat["items"].isArray()) continue;
        QJsonArray jitems_all = cat["items"].toArray();

        for(int jii=0; jii<jitems_all.size(); jii++)
        {
            QJsonArray jitems = jitems_all[jii].toArray();

            if (jitems.size()<2) continue;

            int it_id = jitems[0].toString().toInt();
            int rit_id=-1;
            for(int i=0; i<report.catalogs[rcat_id].reportItems.size(); i++)
            {
                if (report.catalogs[rcat_id].reportItems[i].id == it_id)
                {
                    rit_id = i;
                    break;
                }
            }
            if (rit_id<0) continue;
            if ((jitems.size()-1) != report.catalogs[rcat_id].reportItems[rit_id].reportValues.size()) continue;
            for(int i=1; i<jitems.size(); i++)
            {
                QString val = reportValFromJsong(jitems[i].toString(), report.catalogs[rcat_id].reportItems[rit_id].reportValues[i-1].type);
                report.catalogs[rcat_id].reportItems[rit_id].reportValues[i-1].value = val;
            }//jitems
        }//jitems_all
    }
    return NO_ERROR;
}

QString Fesko::reportValFromJsong(QString val, int type)
{
    /*if ((type == 7) && (val=="on")) val="";*/
    Q_UNUSED(type);
    return val;
}

QString Fesko::reportValueToJson(QString val, int type)
{
    Q_UNUSED(type);
    return val;
}

