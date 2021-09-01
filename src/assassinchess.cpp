#include "assassinchess.h"


AssassinChess::AssassinChess(Index index, QObject *parent) : Chess(parent)
{
    placeIndex=index;
    pixmapPath=":/pixmap/res/quinn.png";
}
