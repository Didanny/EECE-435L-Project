#include "game1view.h"

Game1View::Game1View()
{
    this->setFixedSize(1028,675);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    level1 = new Level1();
    level2 = new Level2();
    level3 = new Level3();
    level4 = new Level4();
    level5 = new Level5();
    level6 = new Level6();
    level7 = new Level7();

    this->setScene(level7);

    this->show();
}

