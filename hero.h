#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <direction.h>
#include <utility.h>
#include <gold.h>

class Hero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = nullptr);
    void setDirection(Direction direction);
    void move(int x);
    void checkCollisions();

private:
    Direction _direction;
    int _gold;

signals:

public slots:
};

#endif // HERO_H
