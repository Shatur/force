#ifndef COMMENTS_H
#define COMMENTS_H

#include <QWidget>

namespace Ui {
class Comments;
}

class Comments : public QWidget
{
    Q_OBJECT

public:
    explicit Comments(QWidget *parent = 0);
    ~Comments();

    bool setup();

private slots:
    void on_backButton_clicked();

private:
    Ui::Comments *ui;
};

#endif // COMMENTS_H
