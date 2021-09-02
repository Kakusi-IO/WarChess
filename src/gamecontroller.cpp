#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    blueTeamChesses.clear();
    redTeamChesses.clear();

    //敌方棋子
    Chess *newTankChess,*newAssassinChess,*newArcherChess;
    newTankChess=new TankChess(Index(3,2),true);
    redTeamChesses<<newTankChess;

    newAssassinChess=new AssassinChess(Index(3,0),true);
    redTeamChesses<<newAssassinChess;

    newArcherChess=new ArcherChess(Index(4,0),true);
    redTeamChesses<<newArcherChess;

}

void GameController::addChess(Chess * newChess)
{
    blueTeamChesses<<newChess;
}

bool GameController::hasWon() const
{
    Chess *tempChess;
    foreach(tempChess,redTeamChesses)
    {
        if(tempChess->alive)
        {
            return false;
        }
    }
    return true;
}

bool GameController::hasLost() const
{
    Chess *tempChess;
    foreach(tempChess,blueTeamChesses)
    {
        if(tempChess->alive)
        {
            return false;
        }
    }
    return true;
}

bool GameController::hasEnemyToAttack() const
{
    QList<double> distances;
    Chess *tempChess;
    foreach(tempChess,redTeamChesses)
    {
        distances<<currentChess->distanceTo(*tempChess);
    }
    double minDistance=*(std::min(distances.begin(),distances.end()));
    return minDistance < currentChess->attackDistance+0.1;
}

void GameController::moveChess(int key)
{


    Index indexAfterMove=Index::moveTo(currentChess->placeIndex,key);
    //不能出边界
    if(!indexAfterMove.isValid())
    {
        return;
    }
    //不能撞墙
    if(colorsOfMaps[currentStage][5*indexAfterMove.y+indexAfterMove.x]==Qt::black)
    {
        return;
    }
    //不能撞人
    Chess *tempChess;
    foreach(tempChess,blueTeamChesses)
    {
        if(tempChess->index()==indexAfterMove)
        {
            return;
        }
    }
    foreach(tempChess,redTeamChesses)
    {
        if(tempChess->index()==indexAfterMove)
        {
            return;
        }
    }

    //可以移动
    currentChess->move(key);
    moved=true;
}

void GameController::actAttack(Chess *lhs, Chess *rhs)
{

    int damage=lhs->attack();
    rhs->beAttacked(damage);
    if(!rhs->alive)
    {
        emit someoneDead();
    }
}


