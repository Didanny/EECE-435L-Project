#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <QFileInfo>
#include <user.h>

class UserService
{
private:
    static UserService *_instance;
    static QString _currentUser;
    UserService();

public:
    static UserService* getInstance();
    bool getUser(QString username, User &user);
    void setCurrentUser(QString username);
    void getCurrentUser(User &user);
};

#endif // USERSERVICE_H
