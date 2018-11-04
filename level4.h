#ifndef LEVEL4_H
#define LEVEL4_H

#include <levelscene.h>
#include <gold.h>
#include <water.h>
#include <boat.h>

class Level4 : public LevelScene
{
public:
    Level4();
    virtual void resetLevel();
    Water *water;
    Gold **gold;
    Boat *boat;
};

#endif // LEVEL4_H
