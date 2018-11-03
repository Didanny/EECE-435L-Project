#include "hero.h"

Hero::Hero(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/hero.png")).scaled(100,100));
    setDirection(RIGHT);
}

void Hero::setDirection(Direction direction)
{
    _direction = direction;
    // TODO: ROTATE Pixmap
}

#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QApplication>
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

        QMutex localMutex;
        QWaitCondition sleepSimulator;
        sleepSimulator.wait(&localMutex, 200);
        QApplication::processEvents();

    }
}
