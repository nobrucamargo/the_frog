#include "mainscreen.h"

MainScreen::MainScreen(QWidget *parent) : QGraphicsView(parent) {

    /*__________iniciando as configs gerais de tela____________________*/
    setFixedSize(width, height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowIcon(QIcon(":/images_design/icon.webp"));
    setWindowTitle("Frogger");
     _startScreen = nullptr;
     _gameScreen = nullptr;
     //_gameOverScreen == nullptr;

    // Chamando a tela inicial
    showScreen(frogger::GScreen);
}

MainScreen::~MainScreen(){}

void MainScreen::showScreen(frogger::Screen screen)
{
    switch(screen){
    /*__________iniciando a tela inicial de jogo, startGameScreen____________________*/
    case frogger::SScreen :
        _startScreen = new StartScreen(frogger::width, frogger::height, this);
        setScene(_startScreen);
        QObject::connect(_startScreen, SIGNAL(start(frogger::Screen)), this, SLOT(showScreen(frogger::Screen)));

        // chamar o destrutor de gameover screen
        break;
    /*________________________iniciando a tela de jogo_______________________________*/
    case frogger::GScreen :
        _gameScreen = new GameScreen(frogger::width, frogger::height, this);
        // Alguns objetos não precisam de um pai na hora da criação, pois são adotados mais tarde
        player = new GameData();
        // player sendo adotado pela cena
        _gameScreen->addItem(player);
        setScene(_gameScreen);

        // Verificação de segurança para não destruir/acessar endereços indevidos
        if (_startScreen != nullptr){
            delete _startScreen;
            _startScreen=nullptr;
        }
        qDebug() << "startScreen destruída";
        break;
    /*________________________iniciando a tela de game over__________________________*/
    case frogger::GOScreen :
        // chamar o construtor de game screen

        // Verificação de segurança para não destruir/acessar endereços indevidos
        if (_gameScreen){
            delete _gameScreen;
            _gameScreen=nullptr;
        }
        qDebug() << "GameScreen destruída";
        break;
    }
}
