#include "gamesartmenu.h"

GameStartMenu::GameStartMenu(QWidget *parent) : QWidget(parent)
{
    btnNewGame = new QPushButton("New Game");
    btnResume = new QPushButton("Resume");

    setVBoxLayout();
}

void GameStartMenu::setVBoxLayout()
{
    loVbox = new QVBoxLayout();

    loVbox->addWidget(btnNewGame);
    loVbox->addWidget(btnResume);

    this->setLayout(loVbox);
}
