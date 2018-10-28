#include "level1.h"

Level1::Level1()
{
    this->setBackgroundBrush(QBrush(QImage(":/images/level1.png").scaledToHeight(675).scaledToWidth(1028)));

    hero = new Hero();
    hero->setPos(100,280);
    this->addItem(hero);
}

#include <QDebug>
void Level1::execute()
{
    qDebug() << "YUP";
}

void Level1::execute(QString block, int i)
{

}
