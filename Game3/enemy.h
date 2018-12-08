#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy();
    QTimer *timer_enemy;
    int speed;

public slots:
    void move();
};

#endif // ENEMY_H
