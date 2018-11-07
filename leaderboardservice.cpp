#include "leaderboardservice.h"

LeaderBoardService* LeaderBoardService::_instance = nullptr;

LeaderBoardService::LeaderBoardService()
{

}

LeaderBoardService *LeaderBoardService::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new LeaderBoardService();
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

    QFile file2("game1boardr.txt");
    line = QString();
    if (file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file2);
        while (!stream.atEnd())
        {
            line = stream.readLine();
            if (true)
            {
                QStringList list = line.split(',');
                game1boardr[list.at(0).toInt()] = list.at(1);

//                qDebug() << game1boardf["dan"];
//                qDebug() << game1boardr[12];
            }
        }
    }
    file2.close();
}

QString LeaderBoardService::getGame1Board()
{
    QString board;
    for (int score : game1boardr.keys())
    {
        board += score + " : " + game1boardr.value(score);
        qDebug() << score << " : " << game1boardr.value(score);
    }
    return board;
}

void LeaderBoardService::addEntry(QString game, QString username, int score)
{
    if (game == QString("game1"))
    {
        game1boardf[username] = score;
        game1boardr[score] = username;
    }
}
