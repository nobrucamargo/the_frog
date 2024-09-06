#include "gamescreen.h"



GameScreen::GameScreen(const int &x, int const &y, QObject *parent) : QGraphicsScene(parent)
{

    /*________________________iniciando a cena_______________________________*/
    setBackgroundBrush(QColor(2, 142, 116, 255));
    /*OBS!!!
     * Criar as dimeções passando x e y inicial e x e y final. A posição não é aqui!!
    */
    setSceneRect(0, 0, x, y);

                    /*----Configura o scenario----*/
    scenario = new QGraphicsRectItem(0, 0, frogger::GS_LIMITE_V, frogger::GS_LIMITE_H);
    scenario->setZValue(0);
    scenario->setPen(QPen(Qt::black));
    scenario->setBrush(QBrush(QPixmap(":/images_design/gamescreen.jpg")));
    scenario->setPos(x*frogger::X_SCENARIO_COEF, y*frogger::Y_SCENARIO_COEF);
    // -1 para não esconder a borda
    edges[0] = new QGraphicsRectItem(-frogger::BASE_PASSO_X-1, 0, frogger::BASE_PASSO_X,
                                     scenario->boundingRect().height(), scenario);
    edges[1] = new QGraphicsRectItem(scenario->boundingRect().width(), 0,
                                     frogger::BASE_PASSO_X, scenario->boundingRect().height(),
                                     scenario);
    // Configura as bordas do cenário para esconder os npcs
    edges[0]->setBrush(QColor(2, 142, 116, 255));
    edges[1]->setBrush(QColor(2, 142, 116, 255));
    edges[0]->setZValue(10);
    edges[1]->setZValue(10);
    edges[0]->setPen(Qt::NoPen);
    edges[1]->setPen(Qt::NoPen);

                    /*-----Cria as vitórias régias-------*/
    QPixmap skin(":/images_design/vitoria_regea.png");
    //scaled() retorna um novo objeto pixmap já redimensionado
    skin = skin.scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y, Qt::KeepAspectRatio);
    for (int i=5; i >= 0; i--){

        vitoriaRegia[i] = new Component(skin, scenario);
        vitoriaRegia[i]->setPos(frogger::BASE_PASSO_X*(0.5+2*i), 0.5*frogger::BASE_PASSO_Y);
        vitoriaRegia[i]->sFriendly(true);
    }


                    /*-----Cria as estradas que incluem os npcs-------*/
    // Iniciar speed conforme gameData(dados do jogador)
    int speed=11/10; // Dado em passo/s
    for (int i=3; i>=0; i--){
        streets[i] = new Stream(speed, 11, scenario->pos().y()+frogger::BASE_PASSO_Y*(9-i), scenario, this);
    }


                        /*-----Cria o sapo-------*/
    skin.load(":/images_design/logo.png");
    skin = skin.scaled(frogger::BASE_PASSO_X, frogger::BASE_PASSO_Y, Qt::KeepAspectRatio);
    frogger = new ControlableComponent(skin, scenario);
    frogger->setPos(0.5*frogger::BASE_PASSO_X, (-0.5+frogger::NR_L)*frogger::BASE_PASSO_Y);

    // Timer para os npcs ocuparem a estrada antes de frogg se mover
    froggerTimer = new QTimer();
    froggerTimer->setSingleShot(true);
    QObject::connect(froggerTimer, &QTimer::timeout, this, &GameScreen::setMvFrogger);
    froggerTimer->start(2500);



    /*________________________iniciando o sapo_______________________________*/


    addItem(scenario);

}

GameScreen::~GameScreen(){
    //delete frogger;
}
