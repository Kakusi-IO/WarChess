#include "tankchess.h"


TankChess::TankChess(Index index,QObject *parent) : Chess(parent)
{
    placeIndex=index;

    hitPoint=1200;
    attackValue=50;
    stepLength=1;
    attackDistance=1;

    pixmapPath=":/pixmap/res/mundo.png";
}

TankChess::TankChess(Index index, bool isEnemy, QObject *parent): Chess(parent)
{
    Q_UNUSED(isEnemy);
    placeIndex=index;

    hitPoint=12;
    attackValue=50;
    stepLength=1;
    attackDistance=1;

    pixmapPath=":/pixmap/res/mundo_enemy.png";
}


void TankChess::beAttacked(int damage)
{
    hitPoint-=0.8*damage;
    if(hitPoint<=0)
    {
        death();
    }
}

QString TankChess::chessName() const
{
    return "祖安狂人";
}
