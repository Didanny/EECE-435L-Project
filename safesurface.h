#ifndef SAFESURFACE_H
#define SAFESURFACE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class SafeSurface : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SafeSurface();
    void setImageAndSize(QString image, int width, int height);

signals:

public slots:
};

#endif // SAFESURFACE_H
