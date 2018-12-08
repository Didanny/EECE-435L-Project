#ifndef GAME3CONTROLLER_H
#define GAME3CONTROLLER_H

#include <QObject>

#include <gamesartmenu.h>
#include <./Game3/game.h>
#include <userservice.h>
#include <leaderboardservice.h>

//Game *game;

class Game3Controller : public QObject
{
    Q_OBJECT
public:
    explicit Game3Controller(QObject *parent = nullptr);
    UserService *userService;
    LeaderBoardService *leaderboardService;

signals:

public slots:
    void gameOver();
};

#endif // GAME3CONTROLLER_H
