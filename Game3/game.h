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
    Q_OBJECT
public:
    Game();
    QTimer *timer;
    Player *player;
    QGraphicsScene *scene;
    Score *score;
    Health *health;
    void lose();

signals:
    void gameLost();

public slots:

};

#endif // Game_H
