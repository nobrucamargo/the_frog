#ifndef MOVABLECOMPONENT_H
#define MOVABLECOMPONENT_H

#include "component.h"
#include <QVector2D>
#include <froggerconfig.h>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QPropertyAnimation>


class MovableComponent : public QObject, public Component {

    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public :
    // Sobrecarda de construtores para ter mais de uma forma de construtor
    explicit MovableComponent(const QPixmap &skin = QPixmap(), QGraphicsItem *parent = nullptr);
    explicit MovableComponent(QGraphicsItem *parent = nullptr);
    // QGraphicsItem interface
    void advance(int phase) override;
    void moveNpc(const int &distance, const int &velocity);

private:

    QPixmap skins[5];

private slots:
    inline void deleteFromScene(void){
        this->scene()->removeItem(this);
        delete(this);
    }
};


#endif // MOVABLECOMPONENT_H
