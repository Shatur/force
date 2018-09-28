#ifndef SINGLETONCONNECT_H
#define SINGLETONCONNECT_H

#include <QObject>
#include <QDebug>

class SingletonConnect : public QObject
{
    Q_OBJECT
public:
    //explicit SingletonConnect(QObject *parent = nullptr);

    static SingletonConnect& getInstance()
    {
        static SingletonConnect s;
        return s;
    }



    QString *getReportData();
    void setReportData(const QString &value);

    QList<QVariantHash> getReportDataShortList() const;
    void appendReportDataShortToList( const QVariantHash &value);

private:
    SingletonConnect() {  }
    ~SingletonConnect() {  }

    SingletonConnect(SingletonConnect const&) = delete;
    SingletonConnect& operator= (SingletonConnect const&) = delete;
    QString catalogsData;  // дані для репортів. Єдиний екземпляр. Моделі каталогів працюють із ним за адресою.
    QList<QVariantHash> reportDataShortList;
signals:
    void report(QString report);
    void report2(QString);
public slots:
};

#endif // SINGLETONCONNECT_H
