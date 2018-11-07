#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <game1scene.h>
#include <level1.h>
#include <game1view.h>
#include <game1controller.h>

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
//    gameController->loadUser("b2");

//    Game1Scene *scene = new Game1Scene();

//    Game1View *view = new Game1View();

//    Game1Controller *controller = new Game1Controller();



//    Level1 *scene = new Level1();

//    QGraphicsView *view = new QGraphicsView();
//    view->setScene(scene);
//    view->setFixedSize(1028,675);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->show();



    return app.exec();
}
