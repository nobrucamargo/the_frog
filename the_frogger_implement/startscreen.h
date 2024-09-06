#ifndef STARTSCREEN_H
#define STARTSCREEN_H

/* Incldues do startScreen */
#include <QGraphicsScene>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include <QRegularExpression>
#include <QValidator>
#include <QGraphicsScene>

/* Includes do startButton */
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include "froggerconfig.h"
#include "QGraphicsDropShadowEffect"

/* Includes do textBox */
#include <QLineEdit>

/*----------------------------------textBox-----------------------------------*/
class InsertString : public QLineEdit{
    Q_OBJECT
public:
    explicit InsertString(const QString &contents, QWidget *parent = nullptr);
protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
};


/*----------------------------------startButton-------------------------------*/
class StartButton : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit StartButton(const int &x, const int &y, const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
    void clicked(void);

};


/*----------------------------------startScreen-------------------------------*/
class StartScreen : public QGraphicsScene
{
    Q_OBJECT
private:
    StartButton* _startButton;
    QLineEdit* insertNickname;

public:
    explicit StartScreen(const int &x, const int &y, QObject* parent = nullptr);
    // Todos os elementos possuem um pai, então não precisa de um destrutor específico

public slots:
    void verifyNickname(void);

signals:
    void start(frogger::Screen);
};

#endif // STARTSCREEN_H
