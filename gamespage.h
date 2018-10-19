#ifndef GAMESPAGE_H
#define GAMESPAGE_H

#include <QWidget>
#include <QtWidgets>

class GamesPage : public QWidget
{
    Q_OBJECT
public:
    explicit GamesPage(QWidget *parent = nullptr);
    QPushButton *btnGame1;
    QPushButton *btnGame2;
    QPushButton *btnGame3;
    QVBoxLayout *loStack;

signals:

public slots:
};

#endif // GAMESPAGE_H
