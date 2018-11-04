#include "safesurface.h"

SafeSurface::SafeSurface()
{

}

void SafeSurface::setImageAndSize(QString image, int width, int height)
{
    this->setPixmap((QPixmap(":/images/" + image + ".png")).scaled(width,height));
}
