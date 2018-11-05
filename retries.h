#ifndef RETRIES_H
#define RETRIES_H

#include <QFont>
#include <QGraphicsTextItem>

class Retries : public QGraphicsTextItem
{
public:
    Retries(QGraphicsItem *parent = nullptr);
    void setRetries(int retries);
    void decrease();
    void updateText();

private:
    int _retries;
};

#endif // RETRIES_H
