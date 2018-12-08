#include <gamespage.h>

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

    QObject::connect(btnGame1,SIGNAL(clicked(bool)),this,SLOT(openGame1()));
    QObject::connect(btnGame3,SIGNAL(clicked(bool)),this,SLOT(openGame3()));
}

void GamesPage::openGame1()
{
//    this->hide();
    game1 = new Game1Controller();
}

void GamesPage::openGame2()
{
//    game2 = new Game2Controller();
}

void GamesPage::openGame3()
{
    game3 = new Game3Controller();
}
