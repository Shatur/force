#ifndef ARCHIVMENTS_H
#define ARCHIVMENTS_H

#include <QWidget>

namespace Ui {
class Archivments;
}

class Archivments : public QWidget
{
    Q_OBJECT

public:
    explicit Archivments(QWidget *parent = 0);
    ~Archivments();

    bool setup();

private slots:
    void on_backButton_clicked();

private:
    Ui::Archivments *ui;
};

#endif // ARCHIVMENTS_H
