#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QDebug>

extern Game * game;


Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    //drew rect

    image = QPixmap(":/images/bullet.png");
    setPixmap(image);


    //connect some stuff
    timer_bullet = new QTimer(this);
    connect(timer_bullet, SIGNAL(timeout()), this, SLOT(move()));

    timer_bullet->start(50);
}

void Bullet::move()
{
    //if collides with enemy, delete enemy and bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase score
            game->score->increase();


            //remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both
            delete colliding_items[i];
            delete this;
            return;
        }

    }

    //move up
    setPos(x(), y()-10);
    if (pos().y() + image.height() < 0)
    {

        timer_bullet->stop();
        scene()->removeItem(this);
        this->deleteLater();
        qDebug() << "Bullet deleted";
    }
}
