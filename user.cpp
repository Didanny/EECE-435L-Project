#include "user.h"

User::User(std::string firstName, std::string lastName, std::string password, std::string username)
{
    setFirstName(firstName);
    setLastName(lastName);
    setPassword(password);
    setUsername(username);
}

void User::read(const QJsonObject &json)
{

}

void User::write(QJsonObject &json) const
{
    json.insert("firstName",_firstName);
    json.insert("lastName",_lastName);
    json.insert("password",_password);
}

void User::saveUser()
{
    QJsonObject userObject;
    write(userObject);

    QJsonDocument userDoc(userObject);

    QFile saveFile(_firstName + ".json");
    saveFile.write(userDoc.toJson());
}

void User::setFirstName(std::string firstName)
{
    _firstName = firstName;
}

void User::setLastName(std::string lastName)
{
    _lastName = lastName;
}

void User::setPassword(std::string password)
{
    _password = password;
}

void User::setUsername(std::string username)
{
    _username = username;
}
