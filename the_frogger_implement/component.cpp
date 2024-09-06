#include "component.h"


Component::Component(const QPixmap &skin, QGraphicsItem *parent): QGraphicsPixmapItem(skin, parent){

    setOffset(-frogger::BASE_PASSO_X/2, -frogger::BASE_PASSO_Y/2);
}
