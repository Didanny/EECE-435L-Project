#ifndef GAME1TIME_H
#define GAME1TIME_H

#include <QDebug>

#include <QFont>
#include <QGraphicsTextItem>
#include <QTimer>

class Game1Time : public QGraphicsTextItem
{
    Q_OBJECT
public:
    static Game1Time* getInstance();
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    int getMinutes();
    int getSeconds();
    void start();
    QTimer *timer;

private:
    Game1Time(QGraphicsItem *parent = nullptr);
    static int _minutes;
    static int _seconds;
    static Game1Time *_instance;

signals:
    void gameOver();

public slots:
    static void countdown();
};

#endif // GAME1TIME_H
