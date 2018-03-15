#ifndef UIHELPER_H
#define UIHELPER_H

#include <QObject>
#include <QListWidget>

class UIHelper : public QObject
{
    Q_OBJECT

    explicit UIHelper(QObject *parent = 0);
public:
    typedef struct _SViewportProperties
    {
        int winWidth;
        int winHeight;

        _SViewportProperties()
        {
            winWidth = 480;
            winHeight = 640;
        }
    }SViewportProperties;

    static UIHelper &ref();

    void setViewportWidth(int width);
    void setViewportHeight(int height);

    SViewportProperties viewProperties();

    void setupListWidget(QListWidget* wgt);
    void addWidgetToList(QListWidget* list, QWidget *wgt);

signals:

public slots:

private:
        SViewportProperties viewProps;
};

static UIHelper& uiHelper = UIHelper::ref();

#endif // UIHELPER_H
