#include "archerchess.h"

ArcherChess::ArcherChess(Index index, QObject *parent) : Chess(parent)
{
    placeIndex=index;
    pixmapPath=":/pixmap/res/caitlyn.png";
}

