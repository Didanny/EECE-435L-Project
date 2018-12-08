#ifndef GAME1CONTROLLER_H
#define GAME1CONTROLLER_H

#include <QObject>

#include <gamesartmenu.h>
#include <game1view.h>
#include <userservice.h>
#include <leaderboardservice.h>

class Game1Controller : public QObject
{
    Q_OBJECT
public:
    explicit Game1Controller(QObject *parent = nullptr);
    GameStartMenu *menu;
    Game1View *view;
    UserService *userService;
    LeaderBoardService *leaderboardService;
    Game1Time *game1time;
    QMessageBox *message;

signals:

public slots:
    void resumeGame();
    void newGame();
    void saveGame();
    void finishGame();
    void gameOver();
};

#endif // GAME1CONTROLLER_H
