#ifndef GAME1VIEW_H
#define GAME1VIEW_H

#include <QGraphicsView>
#include <QObject>

#include <game1info.h>
#include <game1scene.h>
#include <level1.h>
#include <level2.h>
#include <level3.h>
#include <level4.h>
#include <level5.h>
#include <level6.h>
#include <level7.h>

class Game1View : public QGraphicsView
{
    Q_OBJECT
public:
    Game1View();
    Game1Scene *levelsScreen;
    Level1 *level1;
    Level2 *level2;
    Level3 *level3;
    Level4 *level4;
    Level5 *level5;
    Level6 *level6;
    Level7 *level7;
    Level1 *level8;
    LevelScene **levels;
    int *scores;
    int currentLevel;
    void resume(Game1Info& info);
    int getScore();
    Game1Info save();

signals:
    void gameWon();
    void gameOver();

public slots:
    void nextLevel();
    void previousLevel();
    void openLevel();
    void levelWon();
    void finalLevelWon();
    void lose();
};

#endif // GAME1VIEW_H
