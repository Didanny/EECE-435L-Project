#include "hero.h"

Hero::Hero(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/hero.png")).scaled(100,100));
    setDirection(RIGHT);
    _gold = 0;
}

void Hero::setDirection(Direction direction)
{
    _direction = direction;
    // TODO: ROTATE Pixmap
}

#include <QDebug>
void Hero::move(int x)
{
    int step = 45;
    if (x < 0)
    {
        step = -1 * step;
        x = -1 * x;
    }
    qDebug() << "Inside hero.move";
    for (int i = x; i > 0; i--)
    {
        checkCollisions();

        switch(_direction)
        {
        case RIGHT:
            this->setPos(this->x() + step, this->y());
            break;
        case UP:
            this->setPos(this->x(), this->y() - step);
            break;
        case LEFT:
            this->setPos(this->x() - step, this->y());
            break;
        case DOWN:
            this->setPos(this->x(), this->y() + step);
            break;
        default:
            break;
        }
        Utility::delay(200);
    }
}

void Hero::checkCollisions()
{
    QList<QGraphicsItem*> collidingObstacles = collidingItems();

    for (int i = 0; i < collidingObstacles.size(); i++)
    {
        qDebug() << "OBSTACLE " + QString::number(i);
        QGraphicsItem *obstacle = collidingObstacles[i];
        if (typeid(*obstacle) == typeid(Gold))
        {
            scene()->removeItem(obstacle);
//            delete obstacle;
            _gold++;
        }
    }
}

int Hero::getGold()
{
    return _gold;
}
