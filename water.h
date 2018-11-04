#ifndef WATER_H
#define WATER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Water : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Water(QObject *parent = nullptr);
    void setImageAndSize(QString image, int width, int height);

signals:

public slots:
};

#endif // WATER_H
