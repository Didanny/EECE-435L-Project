#ifndef GAMESPAGE_H
#define GAMESPAGE_H

#include <QWidget>
#include <QtWidgets>

#include <game1controller.h>

class GamesPage : public QWidget
{
    Q_OBJECT
public:
    explicit GamesPage(QWidget *parent = nullptr);
    QPushButton *btnGame1;
    QPushButton *btnGame2;
    QPushButton *btnGame3;
    QVBoxLayout *loStack;
    Game1Controller *game1;

signals:

public slots:
    void openGame1();
};

#endif // GAMESPAGE_H
