#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <direction.h>
#include <utility.h>
#include <gold.h>
#include <water.h>
#include <safesurface.h>

//class Boat;

class Hero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = nullptr);
    void setDirection(Direction direction);
    void move(int x);
    void turn(int a);
    void reset();
    void checkCollisions(bool passenger = false);
    int getGold();

private:
    Direction _direction;
    int _gold;

signals:

public slots:
};


