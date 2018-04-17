#ifndef QMLENVIRONMENT_H
#define QMLENVIRONMENT_H

#include <QObject>
#include <QQuickView>
class QmlEnvironment : public QObject
{
    Q_OBJECT
public:
    explicit QmlEnvironment(QObject *parent = nullptr);

    void shift();
    QQuickView* shiftWindow;
private:
    bool shiftStatus = false;
signals:


public slots:
};

#endif // QMLENVIRONMENT_H
