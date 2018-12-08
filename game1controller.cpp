#include "game1controller.h"

Game1Controller::Game1Controller(QObject *parent) : QObject(parent)
{
    message = new QMessageBox();
    menu = new GameStartMenu();

    menu->show();

    userService = UserService::getInstance();
    leaderboardService = LeaderBoardService::getInstance();
//    leaderboardService->loadBoards();
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

    QObject::connect(view->levels[7],SIGNAL(win()),this,SLOT(finishGame()));
    QObject::connect(view,SIGNAL(gameOver()),this,SLOT(gameOver()));
    //    view->resume();

    game1time = Game1Time::getInstance();
    QObject::connect(game1time,SIGNAL(gameOver()),this,SLOT(gameOver()));

}

void Game1Controller::newGame()
{
    menu->close();
    view = new Game1View();
    QObject::connect(view->levelsScreen->btnSave,SIGNAL(clicked(bool)),this,SLOT(saveGame()));
    QObject::connect(view,SIGNAL(gameWon()),this,SLOT(finishGame()));
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
    user.setGame1Info(QString());
    user.saveUser();
    leaderboardService->addEntry("game1",user.getUsername(),view->getScore());
    qDebug() << "FINISH";
    leaderboardService->saveBoards();
    view->close();

//    view->scene()->clear();
//    QGraphicsTextItem *text = view->scene()->addText("CONGRATULATIONS YOU WON");
//    text->setPos(100,100);
}

void Game1Controller::gameOver()
{
    User user;
    userService->getCurrentUser(user);
    user.setGame1Info(QString());
    user.saveUser();
    view->close();

//    QGraphicsTextItem *text = view->scene()->addText("GAME OVER");
//    text->setPos(100,100);
}
