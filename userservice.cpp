#include "userservice.h"

UserService* UserService::_instance = 0;
User* UserService::_currentUser = nullptr;

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
    file.open(QIODevice::ReadOnly);

    QJsonDocument userDoc = QJsonDocument::fromJson(file.readAll());

    file.close();

    QJsonObject userObject(userDoc.object());

    user.read(userObject);
    return true;
}

void UserService::setCurrentUser(QString username)
{
    User user;
    getCurrentUser(user, username);
    _currentUser = new User(user);
}

void UserService::getCurrentUser(User &user, QString username)
{
    getUser(username ,user);
}

void UserService::getCurrentUser(User &user)
{
    getUser(_currentUser->getUsername(),user);
}
