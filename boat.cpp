#include "boat.h"

Boat::Boat(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/boat-right.png")).scaled(175,175));
    setDirection(RIGHT);
    _passenger = nullptr;
}

void Boat::setDirection(Direction direction)
{
    _direction = direction;
}

#include <QDebug>
void Boat::move(int x)
{
    int step = 45;
    if (x < 0)
    {
        step = -1 * step;
        x = -1 * x;
    }
    qDebug() << "Inside boat.move";

    getPassenger();

    for (int i = x; i > 0; i--)
    {
        switch(_direction)
        {
        case RIGHT:
            this->setPos(this->x() + step, this->y());
            if (_passenger != nullptr){
                _passenger->setPos(this->x() + step, this->y());
                _passenger->checkCollisions();
            }
            break;
        case UP:
            this->setPos(this->x(), this->y() - step);
            if (_passenger != nullptr){
                _passenger->setPos(this->x() + step, this->y());
                _passenger->checkCollisions();
            }
            break;
        case LEFT:
            this->setPos(this->x() - step, this->y());
            if (_passenger != nullptr){
                _passenger->setPos(this->x() + step, this->y());
                _passenger->checkCollisions();
            }
            break;
        case DOWN:
            this->setPos(this->x(), this->y() + step);
            if (_passenger != nullptr){
                _passenger->setPos(this->x() + step, this->y());
                _passenger->checkCollisions();
            }
            break;
        default:
            break;
        }
        Utility::delay(200);
    }
    qDebug() << "Finished boat.move";
}

void Boat::turn(int a)
{
    while (a < 0)
    {
        a = 360 + a;
    }

    a = (int)((_direction + a) % 360);
    _direction = (Direction)a;

    qDebug() << "Direction" + QString::number(_direction);

    switch(_direction)
    {
    case RIGHT:
        this->setPixmap((QPixmap(":/images/boat-right.png")).scaled(100,100));
        break;
    case UP:
        this->setPixmap((QPixmap(":/images/boat-up.png")).scaled(100,100));
        break;
    case LEFT:
        this->setPixmap((QPixmap(":/images/boat-left.png")).scaled(100,100));
        break;
    case DOWN:
        this->setPixmap((QPixmap(":/images/boat-down.png")).scaled(100,100));
        break;
    default:
        break;
    }
}

void Boat::getPassenger()
{
    QList<QGraphicsItem*> collidingObstacles = collidingItems();

    for (int i = 0; i < collidingObstacles.size(); i++)
    {
//        qDebug() << "OBSTACLE " + QString::number(i);
        QGraphicsItem *passenger = collidingObstacles[i];
        if (typeid(*passenger) == typeid(Hero))
        {
            _passenger = (Hero*)passenger;
        }
    }
}

void Boat::reset()
{
    this->setPixmap((QPixmap(":/images/boat-right.png")).scaled(175,175));
    setDirection(RIGHT);
    _passenger = nullptr;
}
