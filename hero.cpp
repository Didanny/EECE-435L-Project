#include "hero.h"

Hero::Hero(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/hero-right.png")).scaled(100,100));
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

void Hero::turn(int a)
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
        this->setPixmap((QPixmap(":/images/hero-right.png")).scaled(100,100));
        break;
    case UP:
        this->setPixmap((QPixmap(":/images/hero-up.png")).scaled(100,100));
        break;
    case LEFT:
        this->setPixmap((QPixmap(":/images/hero-left.png")).scaled(100,100));
        break;
    case DOWN:
        this->setPixmap((QPixmap(":/images/hero-down.png")).scaled(100,100));
        break;
    default:
        break;
    }
}

void Hero::reset()
{
    this->setPixmap((QPixmap(":/images/hero-right.png")).scaled(100,100));
    setDirection(RIGHT);
    _gold = 0;
}

void Hero::checkCollisions(bool passenger)
{
    QList<QGraphicsItem*> collidingObstacles = collidingItems();

    bool safe = false;
    bool danger = false;

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
        else if (typeid(*obstacle) == typeid(Water))
        {
            danger = true;
        }
        else if (typeid(*obstacle) == typeid(SafeSurface))
        {
            safe = true;
        }
    }

    if (!safe && danger && !passenger)
    {
        _gold = -1000;
        this->setPixmap((QPixmap(":/images/dead.png")).scaled(100,100));
    }
}

int Hero::getGold()
{
    return _gold;
}
