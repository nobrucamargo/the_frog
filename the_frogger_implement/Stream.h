#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include <QRandomGenerator>
#include <QTimer>
#include <froggerconfig.h>
#include <movablecomponent.h>
#include <QGraphicsObject>
#include <QDebug>

class Stream : public QObject{

    Q_OBJECT
private:
    //QList<MovableComponent* > npcs;
    qreal _height;
    QTimer* _timer;
    // _maxStep: passo máximo para se gerar um novo objt na via
    int _speed, _maxStep;
    QGraphicsItem* _owner;


public:
    explicit Stream(int speed, int maxStep = 11, qreal height = 0,
                    QGraphicsItem* owner = nullptr,
                    QGraphicsScene* scene = nullptr);

public slots:
    void spawnNpc(void);
};

#endif // STREAM_H
