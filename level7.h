#ifndef LEVEL7_H
#define LEVEL7_H

#include <levelscene.h>
#include <gold.h>
#include <water.h>
#include <safesurface.h>

class Level7 : public LevelScene
{
public:
    Level7();
    Gold **gold;
    Water **rivers;
    virtual void resetLevel();
};

#endif // LEVEL7_H
