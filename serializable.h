#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <QJsonObject>

class Serializable
{
public:
    virtual void write(QJsonObject &json) const = 0;
    virtual void read(const QJsonObject &json) = 0;
};

#endif // SERIALIZABLE_H
