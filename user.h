#ifndef USER_H
#define USER_H

#include <QJsonDocument>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <serializable.h>

class User : public Serializable
{
public:
    User(QString firstName, QString lastName, QString password, QString username, QString dob, QString gender);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void saveUser();

private:
    QString _firstName;
    QString _lastName;
    QString _password;
    QString _username;
    QString _dob;
    QString _gender;
    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setPassword(QString password);
    void setUsername(QString username);
    void setDOB(QString dob);
    void setGender(QString gender);
};

#endif // USER_H
