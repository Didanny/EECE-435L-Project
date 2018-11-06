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

    currentMarker = 0;

    time = Game1Time::getInstance();
    this->addItem(time);
    time->setPos(0,0);
    time->setZValue(1000);
    time->start();

    this->setBackgroundBrush(QBrush(QImage(":/images/map.jpg").scaledToHeight(675).scaledToWidth(1028)));
    this->setSceneRect(0,0,1028,675);
}

void Game1Scene::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Click";

    int next = (currentMarker + 1) % 8;
    int prev = ((currentMarker - 1) % -8);

    if (event->key() == Qt::Key_Right)
    {
        qDebug() << "Right click";

        if (markers[next]->getState() != "locked")
        {
            markers[next]->setStageState("current");
            markers[currentMarker]->setStageState("done");
            currentMarker = next;
        }
    }
    else if (event->key() == Qt::Key_Left)
    {
        if (prev < 0) return;
        if (markers[prev]->getState() != "locked")
        {
            markers[prev]->setStageState("current");
            markers[currentMarker]->setStageState("done");
            currentMarker = prev;
        }
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        qDebug() << "Enter";
        enterLevel();
    }
}

void Game1Scene::setMarkers(int i)
{
    int j = 0;
    for (j; j < i; j++)
    {
        markers[j]->setStageState("done");
    }
    markers[i]->setStageState("current");
}

int Game1Scene::getCurrent()
{
    return currentMarker;
}
