#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>


class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bullet();
    QTimer *timer_bullet;

private:
    QPixmap image;


signals:

public slots:
    void move();
};

#endif // BULLET_H
