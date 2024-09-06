#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QtWidgets>
#include <QGraphicsView>
#include <QVBoxLayout>

#include "froggerconfig.h"
#include "gamescreen.h"
#include "gamedata.h"
#include "startscreen.h"

class MainScreen : public QGraphicsView
{
    Q_OBJECT
public:
    MainScreen(QWidget *parent = nullptr);
    ~MainScreen();


private:
    GameScreen* _gameScreen;
    StartScreen* _startScreen;
    GameData* player;

    const qreal width = frogger::width;
    const qreal height = frogger::height;

public slots:
    void showScreen(frogger::Screen screen = frogger::SScreen);
};

#endif // MAINSCREEN_H
