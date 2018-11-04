#ifndef LEVEL5_H
#define LEVEL5_H

#include <levelscene.h>
#include <gold.h>
#include <water.h>
#include <safesurface.h>

class Level5 : public LevelScene
{
public:
    Level5();
    Gold *gold;
    Water *water;
    SafeSurface *island;
    virtual void resetLevel();
};

#endif // LEVEL5_H
