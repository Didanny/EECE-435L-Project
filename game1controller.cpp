#include "game1controller.h"

Game1Controller::Game1Controller(QObject *parent) : QObject(parent)
{
    menu = new GameStartMenu();

    menu->show();

    userService = UserService::getInstance();
    leaderboardService = LeaderBoardService::getInstance();
    leaderboardService->loadBoards();
    leaderboardService->getGame1Board();

    QObject::connect(menu->btnNewGame,SIGNAL(clicked(bool)),this,SLOT(newGame()));
    QObject::connect(menu->btnResume,SIGNAL(clicked(bool)),this,SLOT(resumeGame()));
}

void Game1Controller::resumeGame()
{
    menu->close();
    view = new Game1View();
    QObject::connect(view->levelsScreen->btnSave,SIGNAL(clicked(bool)),this,SLOT(saveGame()));

    //TEST CODE
//    Game1Info info;
//    int *x = new int[8];
//    x[0] = 20;
//    x[1] = 30;
//    x[2] = 40;
//    x[3] = 50;
//    x[4] = 0;
//    x[5] = 0;
//    x[6] = 0;
//    x[7] = 0;
//    info.setLevelScores(x);
//    info.setMinutes(24);
//    info.setSeconds(32);
//    view->resume(info);
//    view->show();
    //TEST CODE END
    User user;
    userService->getCurrentUser(user);
    if (user.getGame1Info().length() < 2)
    {
        // DISPLAY SOME ERROR
        return;
    }
    Game1Info info(user.getGame1Info());
    view->resume(info);
    view->show();

//    view->resume();

}

void Game1Controller::newGame()
{
    menu->close();
    view = new Game1View();
    QObject::connect(view->levelsScreen->btnSave,SIGNAL(clicked(bool)),this,SLOT(saveGame()));
    QObject::connect(view->level8,SIGNAL(win()),this,SLOT(finishGame()));
    view->show();
}

void Game1Controller::saveGame()
{
    Game1Info info = view->save();
    qDebug() << info.toString();

    User user;
    userService->getCurrentUser(user);
    user.setGame1Info(info.toString());
    user.saveUser();
}

void Game1Controller::finishGame()
{
    User user;
    userService->getCurrentUser(user);
    leaderboardService->addEntry("game1",user.getUsername(),view->getScore());
}
