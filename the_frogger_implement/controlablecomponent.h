#ifndef CONTROLABLECOMPONENT_H
#define CONTROLABLECOMPONENT_H

#include "froggerconfig.h"
#include "component.h"
#include <QKeyEvent>
#include <QTimer>

// Herda QWidgets, recebendo a habilidade de interação gráfica, como eventos de teclado

class ControlableComponent : public Component{
private:

public:
    explicit ControlableComponent(const QPixmap &skin, QGraphicsItem *parent = nullptr);
    ~ControlableComponent();
    // sobreescreve o slot de QWidgets
    void keyPressEvent(QKeyEvent *event) override;
};


#endif // CONTROLABLECOMPONENT_H
