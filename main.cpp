#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include <gamecontroller.h>
#include <main_page.h>
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

    return app.exec();
}
