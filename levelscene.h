#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include <QtWidgets>
#include <hero.h>

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

private:
    QString parseFunctionName(QString instruction);
    QString parseObjectName(QString instruction);
    QString parseArgument(QString instruction);

signals:

public slots:
    void execute();
};

#endif // LEVELSCENE_H
