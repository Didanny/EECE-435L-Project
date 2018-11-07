#include "game1info.h"

Game1Info::Game1Info()
{

}

void Game1Info::setSeconds(int sec)
{
    timeSeconds = sec;
}

void Game1Info::setMinutes(int min)
{
    timeMinutes = min;
}

void Game1Info::setLevelScores(int *scores)
{
    levelScores = new int[8];
    for (int i = 0; i < 8; i++)
    {
        levelScores[i] = scores[i];
    }
}
