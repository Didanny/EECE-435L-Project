#include "gamesartmenu.h"

GameSartMenu::GameSartMenu(QWidget *parent) : QWidget(parent)
{
    btnNewGame = new QPushButton("New Game");
    btnResume = new QPushButton("Resume");

    setVBoxLayout();
}

void GameSartMenu::setVBoxLayout()
{
    loVbox = new QVBoxLayout();

    loVbox->addWidget(btnNewGame);
    loVbox->addWidget(btnResume);
}
