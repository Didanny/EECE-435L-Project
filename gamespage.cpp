#include "gamespage.h"

GamesPage::GamesPage(QWidget *parent) : QWidget(parent)
{
    btnGame1 = new QPushButton("Game1");
    btnGame2 = new QPushButton("Game2");
    btnGame3 = new QPushButton("Game3");

    loStack = new QVBoxLayout();
    loStack->addWidget(btnGame1);
    loStack->addWidget(btnGame2);
    loStack->addWidget(btnGame3);

    this->setLayout(loStack);
}
