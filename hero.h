#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include <direction.h>

class Hero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = nullptr);
    void setDirection(Direction direction);

private:
    Direction _direction;

signals:

public slots:
};

#endif // HERO_H
