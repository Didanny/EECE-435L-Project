#include "hero.h"

Hero::Hero(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/hero.png")).scaled(100,100));
    setDirection(RIGHT);
}

void Hero::setDirection(Direction direction)
{
    _direction = Direction;
    // TODO: ROTATE Pixmap
}
