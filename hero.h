#ifndef HERO_H
#define HERO_H

#include <QObject>

class Hero : public QObject
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = nullptr);

signals:

public slots:
};

#endif // HERO_H