#ifndef GAME1VIEW_H
#define GAME1VIEW_H

#include <QGraphicsView>
#include <game1scene.h>
#include <level1.h>
#include <level2.h>
#include <level3.h>
#include <level4.h>
#include <level5.h>

class Game1View : public QGraphicsView
{
public:
    Game1View();
    Game1Scene *levelsScene;
    Level1 *level1;
    Level2 *level2;
    Level3 *level3;
    Level4 *level4;
    Level5 *level5;
};

#endif // GAME1VIEW_H
