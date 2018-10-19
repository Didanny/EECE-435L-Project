#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QGraphicsScene>

#include <stagemarker.h>

class Game1Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Game1Scene();
    StageMarker *marker;
    StageMarker **markers;

signals:

public slots:

};

#endif // GAME1SCENE_H
