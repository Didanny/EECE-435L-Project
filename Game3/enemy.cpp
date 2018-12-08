#include "enemy.h"
#include "game.h"
#include <QDebug>

extern Game *game;


Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    speed = 5 + (game->score->getScore())/6;  //speed increases with the increase of score

    //set random positon
    int random_number = rand() % 700;
    setPos(random_number, 0);

    QPixmap image;
    image = QPixmap(":/images/enemy.png");


    // set pixmap
    setPixmap(image);

    //connect some stuff
    timer_enemy = new QTimer(this);
    connect(timer_enemy, SIGNAL(timeout()), this, SLOT(move()));

    timer_enemy->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+speed);
    if (pos().y() > scene()->height())
    {
        game->health->decrease();
        if (game->health->getHealth() == 0)
        {
            game->lose();
            return;
        }

        timer_enemy->stop();
        scene()->removeItem(this);
        this->deleteLater();
        qDebug() << "Deleted enemy";
    }
//    if (game->health->getHealth() <= 0)
//    {
//        game->gameOver();

//    }
}
