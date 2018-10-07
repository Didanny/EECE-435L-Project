#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <QFileInfo>
#include <user.h>

class UserService
{
private:
    static UserService *_instance;
    UserService();

public:
    static UserService* getInstance();
    bool getUser(QString username, User &user);
};

#endif // USERSERVICE_H
