#include "pixmaplabel.h"

#include <QDebug>

PixmapLabel::PixmapLabel(QWidget *parent): QLabel(parent)
{
    this->setMinimumSize(1,1);
}

int PixmapLabel::heightForWidth(int width) const
{
    return ((qreal)pix.height()*width)/pix.width();
}

QSize PixmapLabel::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}

void PixmapLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}

void PixmapLabel::setPixmap(const QPixmap &p)
{
    pix = p;
    QLabel::setPixmap(p);
}

void PixmapLabel::resizeEvent(QResizeEvent *)
{
    if(!pix.isNull())
    {
            QLabel::setPixmap(pix.scaled(this->size(),
                              Qt::KeepAspectRatio, Qt::SmoothTransformation));
            qDebug()<<this->size();
    }
}
