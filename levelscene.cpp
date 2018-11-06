#include "levelscene.h"

LevelScene::LevelScene()
{
    this->setSceneRect(0,0,1028,675);

    code = new QTextEdit();
    code->resize(200,200);
    code->move(this->width() - code->width() - 10, 10);
    QGraphicsProxyWidget *proxyWidget = this->addWidget(code);
    proxyWidget->setZValue(1000);

    run = new QPushButton("Run");
    run->resize(100,25);
    run->move(this->width() - run->width() - 110, code->height() + 10);
    proxyWidget = this->addWidget(run);
    proxyWidget->setZValue(1000);

    hint = new QPushButton("Hint");
    hint->resize(100,25);
    hint->move(this->width() - hint->width() - 10, code->height() + 10);
    proxyWidget = this->addWidget(hint);
    proxyWidget->setZValue(1000);


    functions = new QTextEdit();
    functions->resize(200,200);
    functions->move(this->width() - functions->width() - 10, 20 + code->height() + run->height());
    proxyWidget = this->addWidget(functions);
    proxyWidget->setZValue(1000);


//    time = Game1Time::getInstance();
//    this->addItem(time);
//    time->setPos(0,0);
//    time->setZValue(1000);
//    time->start();

    retries = new Retries();
    retries->setPos(0,30);
    this->addItem(retries);
    retries->setZValue(1000);

    setRetries(4);
    setScore(0);

    QObject::connect(run,SIGNAL(clicked(bool)),this,SLOT(execute()));
}

#include <QDebug>
void LevelScene::execute()
{
    execute(this->code->toPlainText(),1);
    if (checkWin())
    {
        // WIN
        win();
    }
    _retries--;
    retries->decrease();
    if (_retries == 0)
    {
        // GAME OVER
    }
    resetLevel();
}

void LevelScene::execute(QString block, int i)
{
    QStringList list = block.split('\n');
    qDebug() << list.at(list.size() - 1);
    for (i; i > 0; i--)
    {
        for (int j = 0; j < list.size(); j++)
        {
            QString instruction = list.at(j);
            instruction = instruction.trimmed();
            QString object = parseObjectName(instruction);

            if (object == "hero")
            {
                QString function = parseFunctionName(instruction);
                QString arg = parseArgument(instruction);

                if (function == "move")
                {
                    hero->move(arg.toInt());
                }
                else if (function == "turn")
                {
                    hero->turn(arg.toInt());
                }
            }
            else if (object == "boat")
            {
                QString function = parseFunctionName(instruction);
                QString arg = parseArgument(instruction);

                if (function == "move")
                {
                    boat->move(arg.toInt());
                }
                else if (function == "turn")
                {
                    boat->turn(arg.toInt());
                }
            }
            else if (object == "repeat")
            {
                QString arg = parseArgument(instruction);

                QString repeatBlock;
                while (!(list.at(j+1).contains("end")))
                {
                    repeatBlock += "\n" + list.at(j+1);
                    j++;
                }
                execute(repeatBlock,arg.toInt());
                qDebug() << "REPEAT BLOCK:" << repeatBlock;
                j++;
            }
        }
    }
}

void LevelScene::setRequiredGold(int gold)
{
    _requiredGold = gold;
}

void LevelScene::setRetries(int retries)
{
    _retries = retries;
}

void LevelScene::setScore(int score)
{
    _score = score;
}

int LevelScene::getScore()
{
    return _score;
}

bool LevelScene::checkWin()
{
    if (hero->getGold() >= _requiredGold && _score == 0)
    {
        setScore(_retries * 10);
        return true;
    }
    return false;
}

void LevelScene::resetLevel()
{

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
