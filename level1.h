#ifndef LEVEL1_H
#define LEVEL1_H

#include <levelscene.h>
#include <hero.h>

class Level1 : public LevelScene
{
public:
    Level1();
    Hero *hero;
    virtual void execute(QString block, int i);

public slots:
    virtual void execute();
};

#endif // LEVEL1_H
