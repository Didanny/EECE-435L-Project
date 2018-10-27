#include "game1scene.h"

Game1Scene::Game1Scene()
{
    markers = new StageMarker*[8];

    markers[0] = new StageMarker();
    markers[0]->setName("First");
    markers[0]->setStageState("current");
    markers[0]->setPos(64,0);
    markers[1] = new StageMarker();
    markers[1]->setName("First");
    markers[1]->setStageState("locked");
    markers[1]->setPos(90,175);
    markers[2] = new StageMarker();
    markers[2]->setName("First");
    markers[2]->setStageState("locked");
    markers[2]->setPos(200,200);
    markers[3] = new StageMarker();
    markers[3]->setName("First");
    markers[3]->setStageState("locked");
    markers[3]->setPos(215,380);
    markers[4] = new StageMarker();
    markers[4]->setName("First");
    markers[4]->setStageState("locked");
    markers[4]->setPos(300,445);
    markers[5] = new StageMarker();
    markers[5]->setName("First");
    markers[5]->setStageState("locked");
    markers[5]->setPos(500,410);
    markers[6] = new StageMarker();
    markers[6]->setName("First");
    markers[6]->setStageState("locked");
    markers[6]->setPos(585,350);
    markers[7] = new StageMarker();
    markers[7]->setName("First");
    markers[7]->setStageState("locked");
    markers[7]->setPos(665,250);

    for (int i = 0; i < 8; i++)
    {
        this->addItem(markers[i]);
    }

    this->setBackgroundBrush(QBrush(QImage(":/images/map.jpg").scaledToHeight(675).scaledToWidth(1028)));
    this->setSceneRect(0,0,1028,675);
}