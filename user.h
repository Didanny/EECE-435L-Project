#ifndef USER_H
#define USER_H

#include <QJsonDocument>
#include <QFile>
#include <string>
#include <serializable.h>

class User : public Serializable
{
public:
    User(std::string firstName, std::string lastName, std::string password);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void saveUser();

private:
    std::string _firstName;
    std::string _lastName;
    std::string _password;
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setPassword(std::string password);
};

#endif // USER_H
