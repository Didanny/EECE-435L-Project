#include "retries.h"

Retries::Retries(QGraphicsItem *parent)
{
    setRetries(5);
    updateText();
    this->setDefaultTextColor(Qt::white);
    this->setFont(QFont("arial",16));
}

void Retries::setRetries(int retries)
{
    _retries = retries;
}

void Retries::decrease()
{
    _retries--;
}

void Retries::updateText()
{
    this->setPlainText(QString("Retries: ") + QString::number(_retries));
}
