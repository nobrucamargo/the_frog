#include "movablecomponent.h"


MovableComponent::MovableComponent(const QPixmap &skin, QGraphicsItem *parent) : QObject(), Component(skin, parent){

    // Carrega todas as skins disponíveis para os npcs
    skins[0] = QPixmap(":/images_design/bus_yellow_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                      Qt::KeepAspectRatio, Qt::FastTransformation);
    skins[1] = QPixmap(":/images_design/bus_red_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                   Qt::KeepAspectRatio, Qt::FastTransformation);
    skins[2] = QPixmap(":/images_design/forklift_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                    Qt::KeepAspectRatio, Qt::FastTransformation);
    skins[3] = QPixmap(":/images_design/delivery_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                    Qt::KeepAspectRatio, Qt::FastTransformation);

    // Sorteia uma skin para o npc
    if (skin.isNull()) setPixmap(skins[QRandomGenerator().global()->bounded(4)]);
}

MovableComponent::MovableComponent(QGraphicsItem *parent) : QObject(),
    Component(QPixmap(), parent){

    skins[0] = QPixmap(":/images_design/bus_yellow_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                      Qt::KeepAspectRatio, Qt::FastTransformation);
    skins[1] = QPixmap(":/images_design/bus_red_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                   Qt::KeepAspectRatio, Qt::FastTransformation);
    skins[2] = QPixmap(":/images_design/forklift_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                    Qt::KeepAspectRatio, Qt::FastTransformation);
    skins[3] = QPixmap(":/images_design/delivery_pixel.png").scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y,
                                                                    Qt::KeepAspectRatio, Qt::FastTransformation);
    setPixmap(skins[QRandomGenerator().global()->bounded(4)]);
}

void MovableComponent::advance(int phase){

    if(!phase)
        return;
    setPos(pos().x()+1, pos().y());

    //moveBy(dx, dy);
}

void MovableComponent::moveNpc(const int &distance, const int &velocity){

    QPropertyAnimation* animation = new QPropertyAnimation(this, QByteArray("pos"));
    // V=D/T  =>    T     =   D    /   V
    animation->setDuration(1000*distance/velocity);
    animation->setStartValue(QPointF(0, y()));
    animation->setEndValue(QPointF(distance, y()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    // Deleta os npcs no fim da animação
    QObject::connect(animation, &QPropertyAnimation::destroyed, this, &MovableComponent::deleteFromScene);
}
