#include "game1info.h"

Game1Info::Game1Info()
{

}

Game1Info::Game1Info(QString info)
{
    QStringList list = info.split(',');
    setMinutes(list.at(0).toInt());
    setSeconds(list.at(1).toInt());

    levelScores = new int[8];

    for (int i = 2; i < 10; i++)
    {
        levelScores[i - 2] = list.at(i).toInt();
    }
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

QString Game1Info::getScoresAsString()
{
    QString s = QString();
    for (int i = 0; i < 8; i++)
    {
        s += "," + QString::number(levelScores[i]);
    }
    return s;
}

QString Game1Info::toString()
{
   return QString::number(timeMinutes) + "," + QString::number(timeSeconds) + getScoresAsString();
}
