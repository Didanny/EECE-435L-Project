#ifndef GAME1CONTROLLER_H
#define GAME1CONTROLLER_H

#include <QObject>

#include <gamesartmenu.h>
#include <game1view.h>

class Game1Controller : public QObject
{
    Q_OBJECT
public:
    explicit Game1Controller(QObject *parent = nullptr);
    GameStartMenu *menu;
    Game1View *view;

signals:

public slots:
    void resumeGame();
    void newGame();
};

#endif // GAME1CONTROLLER_H
