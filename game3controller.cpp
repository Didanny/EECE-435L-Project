#include "game3controller.h"

Game *game;

Game3Controller::Game3Controller(QObject *parent) : QObject(parent)
{
    game = new Game();
    game->show();
}
