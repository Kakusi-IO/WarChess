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
