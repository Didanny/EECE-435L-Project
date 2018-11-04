#ifndef LEVEL2_H
#define LEVEL2_H

#include <levelscene.h>

class Level2 : public LevelScene
{
public:
    Level2();
    Gold **gold;
    virtual void resetLevel();
};

#endif // LEVEL2_H
