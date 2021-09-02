#include "assassinchess.h"


AssassinChess::AssassinChess(Index index, QObject *parent) : Chess(parent)
{
    placeIndex=index;
    hitPoint=600;
    attackValue=90;
    stepLength=2;
    attackDistance=2;
    pixmapPath=":/pixmap/res/quinn.png";
}

QString AssassinChess::chessName() const
{
    return "德玛西亚之翼";
}
