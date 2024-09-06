#include <Stream.h>


Stream::Stream(int speed, int maxStep, qreal height, QGraphicsItem* owner, QGraphicsScene* scene) :
    QObject(scene), _height(height), _speed(speed), _maxStep(maxStep), _owner(owner){

    _timer = new QTimer(this);
    _timer->setSingleShot(true);
    QObject::connect(_timer, &QTimer::timeout, this, &Stream::spawnNpc);
    spawnNpc();
}

void Stream::spawnNpc(){

    MovableComponent *npcs = new MovableComponent(QPixmap(), _owner);
    npcs->setPos(-frogger::BASE_PASSO_X/2, _height);
    npcs->moveNpc(13*frogger::BASE_PASSO_X, _speed*frogger::BASE_PASSO_X);

    /* Configura o timer para dar spawn em um novo npc depois de um tempo aleatório de passos do último npc criado */
    // Sorteia um número de passos dentro do intervalo (1, maxStep]
    int steps = QRandomGenerator().global()->bounded(1, _maxStep);

    //nr de passos(random) * comprimento de um passo *
    /*  V = D/T <=> 1/V = T/D => n*D/V = n*T, ou n*dD/V = n*dT.
     *  Logo, se (1/3)T => (1/3)D/V.
     *  Podemos fazer n*D/V, sendo n=1/steps, ou dD/V, sendo steps = dD*n:
     */
    _timer->start((1000)*steps/_speed); // *1000 para converter em segundos

    //Pega lista de itens colidindo com newnpc e verifica se não é outro npc
    // QList<QGraphicsItem* > colliding_items = npc->collidingItems();
    // for (int i=0, n=colliding_items.size(); i<n; i++){

    //     if (typeid(*(colliding_items[i])) == typeid(MovableComponent)){
    //         // Caso newnpc esteja colidindo com outro npc, delete newnpc
    //         scene()->removeItem(newnpc);
    //         delete(newnpc);
    //     }
    // }
}


