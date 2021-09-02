#include "archerchess.h"

ArcherChess::ArcherChess(Index index, QObject *parent) : Chess(parent)
{
    placeIndex=index;
    hitPoint=500;
    attackValue=70;
    stepLength=1;
    attackDistance=3;
    pixmapPath=":/pixmap/res/caitlyn.png";
}

QString ArcherChess::chessName() const
{
    return "皮城女警";
}

