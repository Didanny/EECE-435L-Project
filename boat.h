#ifndef BOAT_H
#define BOAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <direction.h>
#include <utility.h>
#include <hero.h>

class Boat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Boat(QObject *parent = nullptr);
    void setDirection(Direction direction);
    void move(int x);
    void turn(int a);
    void getPassenger();
    void reset();

private:
    Direction _direction;
    QGraphicsPixmapItem *_passenger;

signals:

public slots:
};

#endif // BOAT_H
