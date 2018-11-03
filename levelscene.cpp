#include "levelscene.h"

LevelScene::LevelScene()
{
    this->setSceneRect(0,0,1028,675);

    code = new QTextEdit();
    code->resize(200,200);
    code->move(this->width() - code->width() - 10, 10);
    this->addWidget(code);

    run = new QPushButton("Run");
    run->resize(100,25);
    run->move(this->width() - run->width() - 110, code->height() + 10);
    this->addWidget(run);

    hint = new QPushButton("Hint");
    hint->resize(100,25);
    hint->move(this->width() - hint->width() - 10, code->height() + 10);
    this->addWidget(hint);

    QObject::connect(run,SIGNAL(clicked(bool)),this,SLOT(execute()));
}

#include <QDebug>
void LevelScene::execute()
{
    execute(this->code->toPlainText(),1);
}

void LevelScene::execute(QString block, int i)
{
    QStringList list = block.split('\n');
    qDebug() << list.at(list.size() - 1);
    for (int j = 0; j < list.size(); j++)
    {
        QString instruction = list.at(j);
        QString object = parseObjectName(instruction);

        if (object == "hero")
        {
            QString function = parseFunctionName(instruction);
            QString arg = parseArgument(instruction);

            if (function == "move")
            {
                hero->move(arg.toInt());
            }
        }
        else if (object == "boat")
        {

        }
        else if (object == "repeat")
        {

        }
    }
}

QString LevelScene::parseFunctionName(QString instruction)
{
    QString objectName = parseObjectName(instruction);

    QString function = instruction.right(instruction.length() - objectName.length() - 1);

//    qDebug() << "function: " << function;

    QStringList list = function.split('(');
    return list.at(0);
}

QString LevelScene::parseObjectName(QString instruction)
{
    QStringList list = instruction.split('.');
    return list.size() > 1 ? list.at(0) : instruction.split('(').at(0);
}

QString LevelScene::parseArgument(QString instruction)
{
    QStringList list = instruction.split(QRegularExpression("\\(|\\)"));
    return list.at(1);
}
