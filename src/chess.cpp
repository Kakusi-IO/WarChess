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
    placeIndex=Index(-100,-100);
    alive=false;
}

Index Chess::index() const
{
    return placeIndex;
}

QString Chess::info() const
{
    //名称，生命值（当前），攻击力，攻击距离，步长
    QString returnInfo;
    QString className=metaObject()->className();
    if(className==QString("TankChess"))
    {
        returnInfo="祖安狂人";
    }
    else if(className==QString("AssassinChess"))
    {
        returnInfo="德玛西亚之翼";
    }
    else
    {
        returnInfo="皮城女警";
    }
    returnInfo+="\t生命值:";
    returnInfo+=QString::number(hitPoint);
    returnInfo+="\t攻击力:";
    returnInfo+=QString::number(attackValue);
    returnInfo+="\t攻击距离:";
    returnInfo+=QString::number(attackDistance);
    returnInfo+="\t步长:";
    returnInfo+=QString::number(stepLength);

    return returnInfo;
}

void Chess::move(int key)
{
    //只管移动，不验证合理性
    switch(key)
    {
    case Qt::Key_W:
        placeIndex.y--;
        break;
    case Qt::Key_S:
        placeIndex.y++;
        break;
    case Qt::Key_A:
        placeIndex.x--;
        break;
    case Qt::Key_D:
        placeIndex.x++;
        break;
    }
}

double Chess::distanceTo(const Chess &rhs) const
{
    return Index::distance(placeIndex,rhs.placeIndex);
}



QString Chess::chessName() const
{
    return "棋子基类";
}
