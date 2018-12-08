#include "game3controller.h"

Game *game;

Game3Controller::Game3Controller(QObject *parent) : QObject(parent)
{
    game = new Game();
    game->show();

    QObject::connect(game,SIGNAL(gameLost()),this,SLOT(gameOver()));
}

void Game3Controller::gameOver()
{

}
