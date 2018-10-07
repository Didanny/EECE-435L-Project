#include "user.h"

User::User(QString firstName, QString lastName, QString password, QString username, QString dob, QString gender)
{
    setFirstName(firstName);
    setLastName(lastName);
    setPassword(password);
    setUsername(username);
    setDOB(dob);
    setGender(gender);
}

void User::read(const QJsonObject &json)
{
    setFirstName(json.find("firstName").value().toString());
    setLastName(json.find("lastName").value().toString());
    setPassword(json.find("password").value().toString());
    setUsername(json.find("username").value().toString());
}

void User::write(QJsonObject &json) const
{
    json.insert("firstName",_firstName);
    json.insert("lastName",_lastName);
    json.insert("password",_password);
    json.insert("username",_username);
    json.insert("dob",_dob);
    json.insert("gender",_gender);
}

void User::saveUser()
{
    QJsonObject userObject;
    write(userObject);

    QJsonDocument userDoc(userObject);

    QFile saveFile("./users/" + _username + ".json");
    saveFile.open(QIODevice::WriteOnly);
    QTextStream stream(&saveFile);
    stream << userDoc.toJson();
    saveFile.close();
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

void User::setDOB(QString dob)
{
    _dob = dob;
}

void User::setGender(QString gender)
{
    _gender = gender;
}
