#include "chess.h"

Chess::Chess(QObject *parent) : QObject(parent)
{

}

Chess::Chess(Index index)
{
    placeIndex=index;

}

int Chess::attack()
{
    return attackValue;
}

void Chess::beAttacked(int damage)
{
    hitPoint-=damage;
    if(hitPoint<=0)
    {
        death();
    }
}

void Chess::death()
{
    alive=false;
}

Index Chess::index() const
{
    return placeIndex;
}
