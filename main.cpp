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

    return app.exec();
}
