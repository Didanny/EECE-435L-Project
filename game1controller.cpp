#include "game1controller.h"

Game1Controller::Game1Controller(QObject *parent) : QObject(parent)
{
    menu = new GameStartMenu();

    menu->show();

    QObject::connect(menu->btnNewGame,SIGNAL(clicked(bool)),this,SLOT(newGame()));
    QObject::connect(menu->btnResume,SIGNAL(clicked(bool)),this,SLOT(resumeGame()));
}

void Game1Controller::resumeGame()
{
    menu->close();
    view = new Game1View();

    //TEST CODE
    Game1Info info;
    int *x = new int[8];
    x[0] = 20;
    x[1] = 30;
    x[2] = 40;
    x[3] = 50;
    x[4] = 0;
    x[5] = 0;
    x[6] = 0;
    x[7] = 0;
    info.setLevelScores(x);
    info.setMinutes(24);
    info.setSeconds(32);
    view->resume(info);
    view->show();
    //TEST CODE END

//    view->resume();

}

void Game1Controller::newGame()
{
    menu->close();
    view = new Game1View();
    view->show();
}
