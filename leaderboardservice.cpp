#include "leaderboardservice.h"

LeaderBoardService* LeaderBoardService::_instance = nullptr;

LeaderBoardService::LeaderBoardService()
{

}

LeaderBoardService::~LeaderBoardService()
{

}

LeaderBoardService *LeaderBoardService::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new LeaderBoardService();
        _instance->loadBoards();
    }
    return _instance;
}

void LeaderBoardService::loadBoards()
{
    QFile file("game1boardf.txt");

    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            line = stream.readLine();
            if (line.length() > 1)
            {
                QStringList list = line.split(',');
                game1boardf[list.at(0)] = list.at(1).toInt();

//                qDebug() << game1boardf["dan"];
//                qDebug() << game1boardr[12];
            }
        }
    }
//    qDebug() << line;
    file.close();

    QFile file2("game2boardf.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream2(&file2);
        while (!stream2.atEnd())
        {
            line = stream2.readLine();
            if (line.length() > 1)
            {
                QStringList list = line.split(',');
                game2boardf[list.at(0)] = list.at(1).toInt();
            }
        }
    }
    file2.close();
}

QString LeaderBoardService::getGame1Board()
{
    QString board;
//    for (int score : game1boardr.keys())
//    {
//        board += score + " : " + game1boardr.value(score);
//        qDebug() << score << " : " << game1boardr.value(score);
//    }
    return board;
}

void LeaderBoardService::addEntry(QString game, QString username, int score)
{
    if (game == QString("game1"))
    {
        game1boardf[username] = score;
    }

    if (game == QString("game3"))
    {
        game2boardf[username] = score;
    }
}

void LeaderBoardService::saveBoards()
{
    QFile file1("game1boardf.txt");
    file1.open(QIODevice::WriteOnly);
    QTextStream stream1(&file1);
    for (QString usr : game1boardf.keys())
    {
        stream1 << usr + "," + QString::number(game1boardf.value(usr)) + "\n";
    }
    file1.close();

    QFile file2("game2boardf.txt");
    file2.open(QIODevice::WriteOnly);
    QTextStream stream2(&file2);
    for (QString usr : game2boardf.keys())
    {
        stream2 << usr + "," + QString::number(game2boardf.value(usr)) + "\n";
    }
    file2.close();
}
