#include "bosschess.h"


BossChess::BossChess(Index index,QObject *parent) : Chess(parent)
{
    placeIndex=index;

    hitPoint=3000;
    attackValue=100;
    stepLength=1;
    attackDistance=1;

    pixmapPath=":/pixmap/res/Classic_Mordekaiser_Splash.png";
}

QString BossChess::chessName() const
{
    return "金属大师";
}
