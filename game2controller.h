#ifndef GAME2CONTROLLER_H
#define GAME2CONTROLLER_H

#include <QObject>

class Game2Controller : public QObject
{
    Q_OBJECT
public:
    explicit Game2Controller(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GAME2CONTROLLER_H