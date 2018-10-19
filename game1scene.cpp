#include "game1scene.h"

Game1Scene::Game1Scene()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/map.jpg").scaledToHeight(675).scaledToWidth(1028)));
    this->setSceneRect(0,0,1028,675);
}
