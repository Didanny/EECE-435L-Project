#ifndef LEADERBOARDSERVICE_H
#define LEADERBOARDSERVICE_H

#include <QMap>
#include <QHash>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

typedef QHash<QString, int> LeaderBoardForward;
typedef QMap<int, QString> LeaderBoardReverse;

class LeaderBoardService
{
private:
    static LeaderBoardService *_instance;
    LeaderBoardService();
    LeaderBoardForward game1boardf;

public:
    ~LeaderBoardService();
    static LeaderBoardService* getInstance();
    void loadBoards();
    QString getGame1Board();
    void addEntry(QString game, QString username, int score);
    void saveBoards();
};

#endif // LEADERBOARDSERVICE_H
