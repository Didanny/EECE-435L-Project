#include "level6.h"

Level6::Level6()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/grass.png").scaledToHeight(675).scaledToWidth(1028)));

    water = new Water();
    water->setImageAndSize(QString("river-vert"),140,675);
    water->setPos(300,0);
    this->addItem(water);

    bridge = new SafeSurface();
    bridge->setImageAndSize(QString("bridge"),160,120);
    bridge->setPos(290,90);
    this->addItem(bridge);

    hero = new Hero();
    hero->setPos(600,425);
    this->addItem(hero);

    gold = new Gold*[3];

    gold[0] = new Gold();
    gold[0]->setPos(600,125);
    this->addItem(gold[0]);

    gold[1] = new Gold();
    gold[1]->setPos(125,125);
    this->addItem(gold[1]);

    gold[2] = new Gold();
    gold[2]->setPos(125,425);
    this->addItem(gold[2]);

    setRequiredGold(3);
}

void Level6::resetLevel()
{
    for (int i = 2; i > -1; i--)
    {
        this->addItem(gold[i]);
    }
    hero->setPos(600,425);
    hero->reset();
}
