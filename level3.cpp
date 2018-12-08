#include "level3.h"

Level3::Level3()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/level1.png").scaledToHeight(675).scaledToWidth(1028)));

    hero = new Hero();
    hero->setPos(100,380);
    this->addItem(hero);

    gold = new Gold();

    gold = new Gold();
    gold->setPos(550,100);
    this->addItem(gold);

    setRequiredGold(1);

    QString f;
    f += "hero.move(# steps)\n";
    f += "hero.turn(angle)\n";
    f += "\n";
    f += "angle can only be a multiple of 90, positive angle rotates counter-clockwise, negtive rotates clockwise";
    functions->setText(f);
}

void Level3::resetLevel()
{
    hero->setPos(100,380);
    hero->reset();
    this->addItem(gold);
}
