#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    twTab = new QTabWidget(this);
    profile = new ProfilePage();
    games = new GamesPage();

    twTab->addTab(profile,"Profile");
    twTab->addTab(games,"Games");

    twTab->show();
    int x = 700;
    twTab->setFixedSize(x,x);
}
