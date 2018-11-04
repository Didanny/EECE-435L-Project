#include "level1.h"

Level1::Level1()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/level1.png").scaledToHeight(675).scaledToWidth(1028)));

    hero = new Hero();
    hero->setPos(100,280);
    this->addItem(hero);

    gold = new Gold();
    gold->setPos(400,280);
    this->addItem(gold);

    setRequiredGold(1);
}

void Level1::resetLevel()
{
    hero->setPos(100,280);
    hero->reset();
    this->addItem(gold);
}
