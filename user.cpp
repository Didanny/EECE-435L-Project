#include "user.h"

User::User(QString firstName, QString lastName, QString password, QString username)
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

void User::setFirstName(QString firstName)
{
    _firstName = firstName;
}

void User::setLastName(QString lastName)
{
    _lastName = lastName;
}

void User::setPassword(QString password)
{
    _password = password;
}

void User::setUsername(QString username)
{
    _username = username;
}
