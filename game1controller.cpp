#include "game1controller.h"

Game1Controller::Game1Controller(QObject *parent) : QObject(parent)
{
    menu = new GameStartMenu();

    menu->show();

    QObject::connect(menu->btnNewGame,SIGNAL(clicked(bool)),this,SLOT(newGame()));
}

void Game1Controller::resumeGame()
{
    menu->close();
    view = new Game1View();
//    view->resume();

}

void Game1Controller::newGame()
{
    menu->close();
    view = new Game1View();
    view->show();
}
