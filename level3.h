#ifndef LEVEL3_H
#define LEVEL3_H

#include <levelscene.h>

class Level3 : public LevelScene
{
public:
    Level3();
    Gold *gold;
    virtual void resetLevel();
};

#endif // LEVEL3_H
