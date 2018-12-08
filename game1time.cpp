#include "game1time.h"

Game1Time* Game1Time::_instance = 0;
int Game1Time::_minutes;
int Game1Time::_seconds;

Game1Time::Game1Time(QGraphicsItem *parent)
{
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(countdown()));

    setMinutes(60);
    setSeconds(0);

    this->setPlainText(QString::number(_minutes) + QString(" : 0") + QString::number(_seconds));
    this->setDefaultTextColor(Qt::white);
    this->setFont(QFont("arial",16));
}

Game1Time *Game1Time::getInstance()
{
    if (_instance == 0)
    {
        _instance = new Game1Time();
    }
    return _instance;
}

void Game1Time::setMinutes(int minutes)
{
    _minutes = minutes;
}

void Game1Time::setSeconds(int seconds)
{
    _seconds = seconds;
}

int Game1Time::getMinutes()
{
    return _minutes;
}

int Game1Time::getSeconds()
{
    return _seconds;
}

void Game1Time::start()
{
    timer->start(1000);
}

void Game1Time::countdown()
{
//    qDebug() << "countdown";
    _seconds--;
    if (_seconds < 0)
    {
        if (_minutes == 0)
        {
            getInstance()->gameOver();
        }
        _minutes--;
        _seconds = 59;
    }

    _instance->setPlainText((_minutes < 10 ? QString("0") : QString()) + QString::number(_minutes) + (_seconds < 10 ? QString(" : 0") : QString(" : ")) + QString::number(_seconds));
}
