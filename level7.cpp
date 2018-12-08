#include "level7.h"

Level7::Level7()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/grass.png").scaledToHeight(675).scaledToWidth(1028)));

    rivers = new Water*[3];

    rivers[0] = new Water();
    rivers[0]->setImageAndSize(QString("river-vert"),140,675);
    rivers[0]->setPos(220,425);
    this->addItem(rivers[0]);

    rivers[1] = new Water();
    rivers[1]->setImageAndSize(QString("river-vert"),140,675);
    rivers[1]->setPos(580,425);
    this->addItem(rivers[1]);

    rivers[2] = new Water();
    rivers[2]->setImageAndSize(QString("river"),1028,125);
    rivers[2]->setPos(0,350);
    this->addItem(rivers[2]);

    boat = new Boat();
    boat->setPos(50,330);
    this->addItem(boat);

    hero = new Hero();
    hero->setPos(50,200);
    this->addItem(hero);

    gold = new Gold*[3];

    gold[0] = new Gold();
    gold[0]->setPos(50,525);
    this->addItem(gold[0]);

    gold[1] = new Gold();
    gold[1]->setPos(410,525);
    this->addItem(gold[1]);

    gold[2] = new Gold();
    gold[2]->setPos(750,525);
    this->addItem(gold[2]);

    setRequiredGold(3);

    QString f;
    f += "hero.move(# steps)\n";
    f += "hero.turn(angle)\n";
    f += "boat.move(# steps)\n";
    f += "boat.turn(angle)\n\n";
    f += "repeat(#)\n";
    f += "   // INSERT CODE HERE\n";
    f += "end\n";
    functions->setText(f);
}

void Level7::resetLevel()
{
    for (int i = 3; i > -1; i--)
    {
        this->addItem(gold[i]);
    }
    hero->setPos(50,200);
    hero->reset();
    boat->setPos(50,330);
    boat->reset();
}
