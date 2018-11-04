#include "game1view.h"

Game1View::Game1View()
{
    this->setFixedSize(1028,675);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    level1 = new Level1();
    level2 = new Level2();
    level3 = new Level3();

    this->setScene(level3);

    this->show();
}

