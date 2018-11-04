#include "water.h"

Water::Water(QObject *parent) : QObject(parent)
{

}

void Water::setImageAndSize(QString image, int width, int height)
{
    this->setPixmap((QPixmap(":/images/" + image + ".png")).scaled(width,height));
}
