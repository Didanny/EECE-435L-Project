#include "stagemarker.h"

StageMarker::StageMarker(QObject *parent) : QObject(parent)
{

}

void StageMarker::setName(QString name)
{
    _name = name;
}

void StageMarker::setStageState(QString state)
{
    _state = state;
    this->setPixmap((QPixmap(":/images/" + _state + ".png")).scaled(55,160));
}

QString StageMarker::getState()
{
    return _state;
}
