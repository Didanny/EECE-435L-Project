#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <game1scene.h>

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

//    GameController *gameController = new GameController();
//    gameController->loadUser("b2");

    Game1Scene *scene = new Game1Scene();

    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    view->setFixedSize(1028,675);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return app.exec();
}
