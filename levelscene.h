#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include <QtWidgets>

class LevelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    LevelScene();
    virtual void execute(QString block, int i) = 0;
    QTextEdit *code;
    QTextEdit *functions;
    QPushButton *run;
    QPushButton *hint;

signals:

public slots:
    virtual void execute() = 0;
};

#endif // LEVELSCENE_H
