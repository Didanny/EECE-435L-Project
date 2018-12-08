#include "game.h"
//#include <QPushButton>


Game::Game()
{

    scene = new QGraphicsScene();
    player = new Player();
    score = new Score();
    health = new Health();

    scene->addItem(player);

    //set focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    //add score
    scene->addItem(score);

    //add health
    scene->addItem(health);
    health->setPos(health->x(), health->y()+25);


    this->setScene(scene);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(this->width()/2, this->height() - player->image.height());

    //spawn enemies
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000-100*score->getScore());






}

void Game::gameOver()
{
    scene->clear();
    QGraphicsTextItem *gameOver = new QGraphicsTextItem();
    gameOver->setFont(QFont("times",40));
    gameOver->setDefaultTextColor(Qt::red);
    gameOver->setPlainText("GAME OVER");

    int xPos = this->width()/2 - gameOver->boundingRect().width()/2;
    int yPos = this->height()/2 - gameOver->boundingRect().height()/2;
    gameOver->setPos(xPos, yPos);
    scene->addItem(gameOver);

}

