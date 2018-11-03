#ifndef UTILITY_H
#define UTILITY_H

#include <QMutex>
#include <QWaitCondition>
#include <QApplication>

class Utility
{
public:
    Utility();
    static void delay(int time);
};

#endif // UTILITY_H
