#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    QPixmap image;

signals:

private:


public slots:
    void spawn();
};

#endif // Player_H
