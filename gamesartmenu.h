#ifndef GAMESARTMENU_H
#define GAMESARTMENU_H

#include <QWidget>
#include <QtWidgets>

class GameStartMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameStartMenu(QWidget *parent = nullptr);
    QPushButton *btnNewGame;
    QPushButton *btnResume;
    QVBoxLayout *loVbox;
    void setVBoxLayout();

signals:

public slots:
};

#endif // GAMESARTMENU_H
