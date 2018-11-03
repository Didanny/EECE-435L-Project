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
void Hero::move(int x)
{
    qDebug() << "Inside hero.move";
}
