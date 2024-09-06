#ifndef MOVABLE_COMPONENT_H
#define MOVABLE_COMPONENT_H

#include "component.h"

class movableCompent : public component{
private:

public:
    movableCompent();
    void keyPressEvent(QKeyEvent *event);
};


#endif // MOVABLE_COMPONENT_H
