#ifndef QMLCAMWIDGET_H
#define QMLCAMWIDGET_H

#include <QWidget>

namespace Ui {
class QMLCamWidget;
}

class QMLCamWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QMLCamWidget(QWidget *parent = 0);
    ~QMLCamWidget();

private slots:

    void onImageCaptured(const QImage &preview);

private:
    Ui::QMLCamWidget *ui;
};

#endif // QMLCAMWIDGET_H
