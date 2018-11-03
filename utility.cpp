#include "utility.h"

Utility::Utility()
{

}

void Utility::delay(int time)
{
    QMutex localMutex;
    QWaitCondition sleepSimulator;
    sleepSimulator.wait(&localMutex, time);
    QApplication::processEvents();
}
