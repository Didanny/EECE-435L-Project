#include "user.h"

User::User()
{

}

User::User(QString firstName, QString lastName, QString password, QString username, QString dob, QString gender)
{
    setFirstName(firstName);
    setLastName(lastName);
    setPassword(password);
    setUsername(username);
    setDOB(dob);
    setGender(gender);
    _game1Checkpoint = 0;
}

void User::read(const QJsonObject &json)
{
    setFirstName(json.find("firstName").value().toString());
    setLastName(json.find("lastName").value().toString());
    setPassword(json.find("password").value().toString());
    setUsername(json.find("username").value().toString());
    setDOB(json.find("dob").value().toString());
    setGender(json.find("gender").value().toString());
    setGame1Checkpoint(json.find("game1checkpoint").value().toInt());
}

void User::write(QJsonObject &json) const
{
    json.insert("firstName",_firstName);
    json.insert("lastName",_lastName);
    json.insert("password",_password);
    json.insert("username",_username);
    json.insert("dob",_dob);
    json.insert("gender",_gender);
    json.insert("game1checkpoint",_game1Checkpoint);
}

void User::saveUser()
{
    QJsonObject userObject;
    write(userObject);

    QJsonDocument userDoc(userObject);

    QFile saveFile("./" + _username + ".json");
    saveFile.open(QIODevice::WriteOnly);
    QTextStream stream(&saveFile);
    stream << userDoc.toJson();
    saveFile.close();
}

bool User::authenticate(QString password)
{
    return password == _password;
}

QString User::getFirstName()
{
    return _firstName;
}

QString User::getLastName()
{
    return _lastName;
}

QString User::getDOB()
{
    return _dob;
}

QString User::getUsername()
{
    return _username;
}

bool User::isDOB()
{
    QDate today;
    today = today.currentDate();
    return _dob.mid(4,5) == today.toString().mid(4,5);
}

void User::setGame1Checkpoint(int checkpoint)
{
    _game1Checkpoint = checkpoint;
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
