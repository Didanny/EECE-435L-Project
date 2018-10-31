#ifndef LEVEL1_H
#define LEVEL1_H

#include <levelscene.h>
#include <hero.h>
#include <gold.h>

class Level1 : public LevelScene
{
public:
    Level1();
    Gold *gold;

};

#endif // LEVEL1_H
