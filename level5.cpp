#include "level5.h"

Level5::Level5()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/level1.png").scaledToHeight(675).scaledToWidth(1028)));

    water = new Water();
    water->setImageAndSize(QString("ocean"),1028,675);
    this->addItem(water);

    island = new SafeSurface();
    island->setImageAndSize(QString("island"),200,200);
    island->setPos(615,400);
    this->addItem(island);

    boat = new Boat();
    boat->setPos(175,400);
    this->addItem(boat);

    hero = new Hero();
    hero->setPos(675,450);
    this->addItem(hero);

    gold = new Gold();
    gold->setPos(200,70);
    this->addItem(gold);

    setRequiredGold(1);
}

void Level5::resetLevel()
{
    this->addItem(gold);
    boat->setPos(175,400);
    boat->reset();
    hero->setPos(675,450);
    hero->reset();
}
