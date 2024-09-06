#include "gamedata.h"
#include <QFont>

GameData::GameData(QGraphicsTextItem *parent) : QGraphicsTextItem(parent)
{
    /*-------------Definições padrões-------------*/
    oneUp = 0;
    // Buscar na memória
    hScore = 0;
    froggsToSave = 6;
    froggsSaved = 0;
    QString* nickename = new QString("New player");

    /*-------------Mostrando as definições--------*/
    setPlainText(*nickename);
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("times", 16));

}

GameData::~GameData(){}

void GameData::sNickname(QString newNickname){
    *nickname = newNickname;
}

void GameData::sHScore(){
    hScore++;
}

void GameData::sFroggsToSave(){
    froggsToSave--;
};

void GameData::sFroggsSaved(){
    froggsSaved++;
}

void GameData::sOneUp(){
    oneUp++;
}

QString GameData::gNickname()
{
    return *nickname;
}

