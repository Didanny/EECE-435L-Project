#ifndef LEVEL6_H
#define LEVEL6_H

#include <levelscene.h>
#include <gold.h>
#include <water.h>
#include <safesurface.h>

class Level6 : public LevelScene
{
public:
    Level6();
    Gold **gold;
    SafeSurface *bridge;
    Water *water;
    virtual void resetLevel();
};

#endif // LEVEL6_H
