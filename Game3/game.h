#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "score.h"
#include "health.h"
#include <QTimer>


class Game: public QGraphicsView
{
public:
    Game();
    QTimer *timer;
    Player *player;
    QGraphicsScene *scene;
    Score *score;
    Health *health;
    void gameOver();


};

#endif // Game_H
