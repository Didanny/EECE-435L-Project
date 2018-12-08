#include "player.h"
#include "bullet.h"
#include "enemy.h"

Player::Player(QObject *parent) : QObject(parent)
{
    image = QPixmap(":/images/player.png");
    setPixmap(image);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
        if(pos().x() > 0)
            this->setPos(x()-10, y());
    if(event->key()==Qt::Key_Right)
        if(pos().x() + image.width() < 800)
            this->setPos(x()+10, y());
    if(event->key()==Qt::Key_Space)
    {
        //Create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        this->scene()->addItem(bullet);
    }

}

void Player::spawn()
{
 //create an enemy
   Enemy *enemy = new Enemy();
   scene()->addItem(enemy);

}
