#include "level2.h"

Level2::Level2()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/level1.png").scaledToHeight(675).scaledToWidth(1028)));

    hero = new Hero();
    hero->setPos(350,280);
    this->addItem(hero);

    gold = new Gold*[2];

    gold[0] = new Gold();
    gold[0]->setPos(650,280);
    this->addItem(gold[0]);

    gold[1] = new Gold();
    gold[1]->setPos(50,280);
    this->addItem(gold[1]);

    setRequiredGold(2);

    QString f;
    f += "hero.move(# steps)";
    functions->setText(f);
}

void Level2::resetLevel()
{
    for (int i = 1; i > -1; i--)
    {
        this->addItem(gold[i]);
    }
    hero->setPos(350,280);
    hero->reset();
}
