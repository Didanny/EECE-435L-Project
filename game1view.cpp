#include "game1view.h"

Game1View::Game1View()
{
    this->setFixedSize(1028,675);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    level1 = new Level1();

    this->setScene(level1);

    this->show();
}
