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
    User(QString firstName, QString lastName, QString password, QString username);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void saveUser();

private:
    QString _firstName;
    QString _lastName;
    QString _password;
    QString _username;
    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setPassword(QString password);
    void setUsername(QString username);
};

#endif // USER_H
