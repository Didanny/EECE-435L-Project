#include "game3controller.h"

Game *game;

Game3Controller::Game3Controller(QObject *parent) : QObject(parent)
{
    game = new Game();
    game->show();

    userService = UserService::getInstance();

    QObject::connect(game,SIGNAL(gameLost()),this,SLOT(gameOver()));
}

void Game3Controller::gameOver()
{
    User user;
    userService->getCurrentUser(user);
    if (user.getGame3Info().toInt() < game->getScore())
    {
        qDebug() << "SCORE:" << game->getScore();
        qDebug() << "SCORE:" << QString::number(game->getScore());
        user.setGame3Info(QString::number(game->getScore()));
    }
    user.saveUser();
}
