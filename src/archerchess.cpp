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

ArcherChess::ArcherChess(Index index, bool isEnemy, QObject *parent): Chess(parent)
{
    Q_UNUSED(isEnemy);
    placeIndex=index;
    hitPoint=5;
    attackValue=70;
    stepLength=1;
    attackDistance=3;
    pixmapPath=":/pixmap/res/caitlyn_enemy.png";
}


QString ArcherChess::chessName() const
{
    return "皮城女警";
}

