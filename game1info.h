#ifndef GAME1INFO_H
#define GAME1INFO_H

#include <QString>
#include <QStringList>

class Game1Info
{
public:
    Game1Info();
    Game1Info(QString info);
    int timeSeconds;
    int timeMinutes;
    int *levelScores;
    void setSeconds(int sec);
    void setMinutes(int min);
    void setLevelScores(int *scores);
    QString getScoresAsString();
    QString toString();
};

#endif // GAME1INFO_H
