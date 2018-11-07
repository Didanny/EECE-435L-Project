#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QtWidgets>

#include <stagemarker.h>
#include <game1time.h>

class Game1Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Game1Scene();
    StageMarker *marker;
    StageMarker **markers;
    int currentMarker;
    Game1Time *time;
    void keyPressEvent(QKeyEvent *event);
    void setMarkers(int i);
    int getCurrent();
    QPushButton *btnSave;


signals:
    void enterLevel();

public slots:

};

#endif // GAME1SCENE_H
