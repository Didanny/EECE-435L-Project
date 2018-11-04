#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include <QtWidgets>
#include <hero.h>
#include <game1time.h>
#include <boat.h>

class LevelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    LevelScene();
    void execute(QString block, int i);
    QTextEdit *code;
    QTextEdit *functions;
    QPushButton *run;
    QPushButton *hint;
    Hero *hero;
    Boat *boat;
    void setRequiredGold(int gold);
    void setRetries(int retries);
    void setScore(int score);
    bool checkWin();
    Game1Time *time;
    virtual void resetLevel();

private:
    QString parseFunctionName(QString instruction);
    QString parseObjectName(QString instruction);
    QString parseArgument(QString instruction);
    int _requiredGold;
    int _retries;
    int _score;

signals:

public slots:
    void execute();
};

#endif // LEVELSCENE_H
