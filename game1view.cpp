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
    level8 = new Level1();

    levelsScreen = new Game1Scene();

    levels = new LevelScene*[8];
    levels[0] = level1;
    levels[1] = level2;
    levels[2] = level3;
    levels[3] = level4;
    levels[4] = level5;
    levels[5] = level6;
    levels[6] = level7;
    levels[7] = level8;

    scores = new int[8];
    for (int i = 0; i < 8; i++)
    {
        scores[i] = 0;
    }

    currentLevel = 0;

    this->setScene(levelsScreen);

//    this->show();

    QObject::connect(levelsScreen,SIGNAL(enterLevel()),this,SLOT(openLevel()));

    for (int i = 0; i < 8; i++)
    {
        QObject::connect(levels[i],SIGNAL(win()),this,SLOT(levelWon()));
    }
}

void Game1View::resume(Game1Info &info)
{
    Game1Time::getInstance()->setMinutes(info.timeMinutes);
    Game1Time::getInstance()->setSeconds(info.timeSeconds);
    for (int i = 0; i < 8; i++)
    {
        scores[i] = info.levelScores[i];
        if (scores[i] !=0 ) currentLevel++;
    }
    currentLevel++;
    levelsScreen->setMarkers(currentLevel);
}

Game1Info Game1View::save()
{
    Game1Info info;
    info.setMinutes(Game1Time::getInstance()->getMinutes());
    info.setSeconds(Game1Time::getInstance()->getSeconds());
    info.setLevelScores(scores);
    return info;
}

void Game1View::nextLevel()
{
    currentLevel = (currentLevel + 1) % 8;
}

void Game1View::previousLevel()
{
    currentLevel = (currentLevel - 1) % 8;
}

void Game1View::openLevel()
{
    this->setScene(levels[levelsScreen->getCurrent()]);
    levels[levelsScreen->getCurrent()]->addItem(Game1Time::getInstance());
}

void Game1View::levelWon()
{
    currentLevel++;
    levelsScreen->setMarkers(currentLevel);
    this->setScene(levelsScreen);
    levelsScreen->addItem(Game1Time::getInstance());
}

