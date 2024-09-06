#include "controlablecomponent.h"

#include <QtDebug>

ControlableComponent::ControlableComponent(const QPixmap &skin, QGraphicsItem *parent) : Component(skin, parent){}

ControlableComponent::~ControlableComponent(){}

/** Trata os eventos de comando de movimentos, setas ou awsd
  *
 */
void ControlableComponent::keyPressEvent(QKeyEvent *event)
{
    // Se comando para pular && próximo passo não for fora do limite
    if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_A) &&
        (pos().x()-frogger::BASE_PASSO_X > 0))
    {
        setX(x()-frogger::BASE_PASSO_X);
    }

    else if ((event->key() == Qt::Key_Right || event->key() == Qt::Key_D)&&
             (pos().x()+frogger::BASE_PASSO_X < frogger::GS_LIMITE_V))
    {
        setX(x()+frogger::BASE_PASSO_X);
    }

    else if ((event->key() == Qt::Key_Down || event->key() == Qt::Key_S)&&
             (pos().y()+frogger::BASE_PASSO_Y < frogger::GS_LIMITE_H))
    {
        setY(y()+frogger::BASE_PASSO_Y);
    }

    else if ((event->key() == Qt::Key_Up || event->key() == Qt::Key_W)&&
             (pos().y()-frogger::BASE_PASSO_Y > 0))
    {
        setY(y()-frogger::BASE_PASSO_Y);
    }
    // Chama a implementação padrão de keyPressEvent para tratar eventos de teclado padrões, como Alt+F4
    else {
        qDebug() << "Nenhuma tecla útil!";
        QGraphicsPixmapItem::keyPressEvent(event);
    }
}


