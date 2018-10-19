#ifndef STAGEMARKER_H
#define STAGEMARKER_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include <stagestate.h>

class StageMarker : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit StageMarker(QObject *parent = nullptr);
    void setName(QString name);
    void setStageState(QString state);

private:
    QString _state;
    QString _name;

signals:

public slots:
};

#endif // STAGEMARKER_H
