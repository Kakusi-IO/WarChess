#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "chess.h"
#include "tankchess.h"
#include "assassinchess.h"
#include "archerchess.h"
#include "bosschess.h"
#include "includedLibs.h"

#include <QObject>
#include <QList>

class GameController : public QObject
{
    Q_OBJECT
    friend class GameWindow;
    friend class WindowController;
    QList<Chess*>blueTeamChesses;
    QList<Chess*>redTeamChesses;
    int currentStage=0; //当前的关卡数，取值为0或1
    int chessesHasSetted=0;
    Chess *currentChess;
    bool moved=true;
    bool attackActed=true;
    QSound *attackSound;
    QList<QString> diary;

    void moveChess(int);
    void actAttack(Chess*,Chess*);

    //判断当前蓝色方棋子射程内是否有攻击目标
    bool hasEnemyToAttack() const;

    //用于自动移动、攻击
    bool hasEnemyToAutoAttack() const;
    void autoMoveChess(); //移动红色方的currentChess
    void autoAttack();//currentChess发动攻击
    Chess* findTheNearestEnemy();
    bool canBeMovedTo(Index);
    int signum(int);
    void initReadTeam(int stage=0);
    void restart(int stage=0);
    QString currentTime();

public:
    explicit GameController(QObject *parent = nullptr);
    void addChess(Chess*);
    QColor colorsOfMaps[2][25]=
    {
        //第一关的地图
        {
            Qt::yellow,Qt::green,Qt::black,Qt::green,Qt::green,
            Qt::green,Qt::yellow,Qt::green,Qt::green,Qt::green,
            Qt::green,Qt::green,Qt::yellow,Qt::green,Qt::green,
            Qt::green,Qt::green,Qt::green,Qt::yellow,Qt::green,
            Qt::green,Qt::green,Qt::black,Qt::green,Qt::yellow,
        },
        //第二关的地图
        {
            Qt::red,Qt::green,Qt::green,Qt::green,Qt::red,
            Qt::green,Qt::green,Qt::green,Qt::green,Qt::green,
            Qt::yellow,Qt::yellow,Qt::yellow,Qt::yellow,Qt::yellow,
            Qt::green,Qt::green,Qt::green,Qt::green,Qt::green,
            Qt::red,Qt::green,Qt::green,Qt::green,Qt::red,
        }
    };
    int chessesPerStage[2]={3,4}; //第一关三个棋子，第二关四个棋子，可多放一个射手
    bool hasWon() const;
    bool hasLost() const;

    //判断当前蓝色方棋子射程内是否有攻击目标





signals:
    void someoneDead();

public slots:

};

#endif // GAMECONTROLLER_H
