#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QGraphicsScene>
#include <Stream.h>
#include "controlablecomponent.h"
#include "movablecomponent.h"
#include <component.h>
#include "froggerconfig.h"
#include <QDebug>


class GameScreen : public QGraphicsScene
{
    Q_OBJECT
public:
    // O uso de explicit evita que o compilador use este construtor para realizar
    // conversões implícitas. Por exemplo, sem explicit, se eu passar um QObject* para
    // uma função, esse construtor poderia ser chamado para criar um gameScreen através
    // do QObject* em questão. O mesmo poderia ocorrer ao fazer gameScreen* obj = QObject;
    explicit GameScreen(const int &x, const int &y, QObject *parent = nullptr);

    ~GameScreen();
private:
    QGraphicsRectItem* scenario;
    QGraphicsRectItem* edges[2];
    Component* vitoriaRegia[6];
    Stream* streets[4];
    ControlableComponent* frogger;
    QTimer *froggerTimer;
public slots:
    inline void setMvFrogger(void){
        frogger->setFlag(QGraphicsItem::ItemIsFocusable);
        frogger->setFocus();
    }
    //void addNpc();
};

#endif // GAMESCREEN_H



