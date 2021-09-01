#include "tankchess.h"


TankChess::TankChess(Index index,QObject *parent) : Chess(parent)
{
    placeIndex=index;
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
