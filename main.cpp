#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include <gamecontroller.h>
/**
 * \mainpage EECE-435L-Project
 * \author Danny Abraham
 * \author Simon Tchaghlassian
 * \version 1.0
 * */

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    GameController *gameController = new GameController();
    gameController->loadUser("b2");

//    main_page *main = new main_page();
//    main->show();

//    MainWidget *m = new MainWidget();
//    m->show();

//    ProfilePage *profile = new ProfilePage();
//    profile->show();

//    GamesPage *g = new GamesPage();
//    g->show();

    return app.exec();
}
