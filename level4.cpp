#include "level4.h"

Level4::Level4()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/level4.png").scaledToHeight(675).scaledToWidth(1028)));

    water = new Water();
    water->setImageAndSize(QString("river"),1028,125);
    water->setPos(0,350);
    this->addItem(water);

    boat = new Boat();
    boat->setPos(100,325);
    this->addItem(boat);

    hero = new Hero();
    hero->setPos(100,520);
    this->addItem(hero);

    gold = new Gold*[2];

    gold[0] = new Gold();
    gold[0]->setPos(600,375);
    this->addItem(gold[0]);

    gold[1] = new Gold();
    gold[1]->setPos(600,50);
    this->addItem(gold[1]);

    setRequiredGold(2);

    QString f;
    f += "hero.move(# steps)\n";
    f += "hero.turn(angle)\n";
    f += "boat.move(# steps)\n";
    f += "boat.turn(angle)\n";
    f += "\n";
    f += "angle can only be a multiple of 90, positive angle rotates counter-clockwise, negtive rotates clockwise";
    functions->setText(f);
}

void Level4::resetLevel()
{
    for (int i = 1; i > -1; i--)
    {
        this->addItem(gold[i]);
    }
    hero->setPos(100,520);
    hero->reset();
    boat->setPos(100,325);
    boat->reset();
}
