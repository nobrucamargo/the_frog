#ifndef COMPONENT_H
#define COMPONENT_H

#include <QGraphicsPixmapItem>
#include <froggerconfig.h>

class Component : public QGraphicsPixmapItem
{
public:
    explicit Component(const QPixmap &skin, QGraphicsItem *parent = nullptr);

    inline bool gFriendly(void){ return friendly;}
    inline void sFriendly(bool state){ friendly = state;}

private:
    bool friendly;
};

#endif // COMPONENT_H
