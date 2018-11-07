#ifndef GAME1INFO_H
#define GAME1INFO_H


class Game1Info
{
public:
    Game1Info();
    int timeSeconds;
    int timeMinutes;
    int *levelScores;
    void setSeconds(int sec);
    void setMinutes(int min);
    void setLevelScores(int *scores);
};

#endif // GAME1INFO_H
