#include "userservice.h"

UserService* UserService::_instance = 0;

UserService::UserService()
{

}

UserService *UserService::getInstance()
{
    if (_instance == 0)
    {
        _instance = new UserService();
    }
    return _instance;
}

bool UserService::getUser(QString username, User &user)
{
    QFile file;
    QString path = "./" + username + ".json";
    if (!(QFileInfo::exists(path) && QFileInfo(path).isFile()))
    {
        return false;
    }
    file.setFileName(path);

    QJsonDocument userDoc = QJsonDocument::fromJson(file.readAll());

    file.close();

    QJsonObject userObject(userDoc.object());

    user.read(userObject);
    return true;
}
