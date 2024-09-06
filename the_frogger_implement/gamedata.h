#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QString>

class GameData : public QGraphicsTextItem
{
    Q_OBJECT
private:
    QString* nickname;
    int oneUp, hScore, froggsToSave, froggsSaved;
public:
    explicit GameData(QGraphicsTextItem *parent = nullptr);
    ~GameData();

    /*----Seters----*/
    void sNickname(QString newNickname);
    void sOneUp();
    void sHScore();
    void sFroggsToSave();
    void sFroggsSaved();
   // void initData(int);
   // void upDateGameData(void);

    /*-----geters----*/
    QString gNickname(void);
    int gOneUp();
    int gHScore();
    int gFroggsToSave();
    int gFroggsSaved();
};

#endif // GAMEDATA_H
