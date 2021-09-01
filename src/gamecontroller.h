#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "chess.h"
#include <QObject>
#include <QList>

class GameController : public QObject
{
    Q_OBJECT
    friend class GameWindow;

    QList<Chess*>blueTeamChesses;
    QList<Chess*>redTeamChesses;
    int currentStage=0; //当前的关卡数，取值为0或1
    int chessesHasSetted=0;
public:
    explicit GameController(QObject *parent = nullptr);
    void addChess(Chess*);
    QColor colorsOfMap[2][25]=
    {
        //第一关的地图
        {
            Qt::yellow,Qt::green,Qt::black,Qt::green,Qt::green,
            Qt::green,Qt::yellow,Qt::green,Qt::green,Qt::green,
            Qt::green,Qt::green,Qt::yellow,Qt::green,Qt::green,
            Qt::green,Qt::green,Qt::green,Qt::yellow,Qt::green,
            Qt::green,Qt::green,Qt::black,Qt::green,Qt::yellow,
        },
        //第二关的地图 //todo：还没设计
        {
            Qt::yellow,Qt::green,Qt::black,Qt::green,Qt::green,
            Qt::green,Qt::yellow,Qt::green,Qt::green,Qt::green,
            Qt::green,Qt::green,Qt::yellow,Qt::green,Qt::green,
            Qt::green,Qt::green,Qt::green,Qt::yellow,Qt::green,
            Qt::green,Qt::green,Qt::black,Qt::green,Qt::yellow,
        }
    };
    int chessesPerStage[2]={3,4}; //第一关三个棋子，第二关四个棋子，可多放一个射手
signals:

};

#endif // GAMECONTROLLER_H
