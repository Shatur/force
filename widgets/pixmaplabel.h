#ifndef PIXMAPLABEL_H
#define PIXMAPLABEL_H

#include <QWidget>
#include <QLabel>

class PixmapLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PixmapLabel(QWidget *parent = 0);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;

protected:
    void mousePressEvent ( QMouseEvent * event );

public slots:
    void setPixmap (const QPixmap & p);
    virtual void resizeEvent(QResizeEvent *);

signals:
    void clicked();

private:
    QPixmap pix;
};

#endif // PIXMAPLABEL_H
