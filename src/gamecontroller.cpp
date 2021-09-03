#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    blueTeamChesses.clear();
    redTeamChesses.clear();
    initReadTeam();
}

void GameController::addChess(Chess * newChess)
{
    blueTeamChesses<<newChess;
}

bool GameController::hasWon() const
{
    Chess *tempChess;
//    if(!redTeamChesses.isEmpty())
//    {
//        return false;
//    }
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
    if(blueTeamChesses.isEmpty())
    {
        return false;
    }
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
        if(currentChess->attackDistance+0.01 > currentChess->distanceTo(*tempChess))
        {
            return true;
        }
    }
    return false;
}

bool GameController::hasEnemyToAutoAttack() const
{
    QList<double> distances;
    Chess *tempChess;
    foreach(tempChess,blueTeamChesses)
    {
        distances<<currentChess->distanceTo(*tempChess);
        if(currentChess->attackDistance+0.01 > currentChess->distanceTo(*tempChess))
        {
            return true;
        }
    }
    return false;
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
//    qDebug()<<lhs->chessName()<<" 攻击了 "<<rhs->chessName();
    if(!rhs->alive)
    {
        emit someoneDead();
    }
}

void GameController::autoMoveChess()
{
    if(hasEnemyToAutoAttack())
    {
//        qDebug()<<currentChess->chessName()<<" "<<"有自动攻击的目标,无需移动";
//        moved=true;//跳过移动
        return;
    }
//    qDebug()<<currentChess->chessName()<<" "<<"没有自动攻击的目标";
     //靠近最近的敌人
    Chess *goalChess=findTheNearestEnemy();
    int deltaX=goalChess->index().x-currentChess->index().x;
    int deltaY=goalChess->index().y-currentChess->index().y;
    //优先度：deltax, deltay, -deltax, -deltay
    Index currentIndex=currentChess->index();
    if(signum(deltaX)!=0)
    {
        if(canBeMovedTo(Index(currentIndex.x+signum(deltaX),currentIndex.y))) //可以x方向靠近
        {

            if(deltaX>0)
            {
                currentChess->move(Qt::Key_D);
            }
            else
            {
                currentChess->move(Qt::Key_A);
            }
//            moved=true;
            return;
        }
    }
    if(signum(deltaY)!=0)
    {
        if(canBeMovedTo(Index(currentIndex.x,currentIndex.y+signum(deltaY)))) //可以y方向靠近
        {
            if(deltaY>0)
            {
                currentChess->move(Qt::Key_S);
            }
            else
            {
                currentChess->move(Qt::Key_W);
            }
//            moved=true;

            return;
        }
    }
    if(signum(deltaX)!=0)
    {
        if(canBeMovedTo(Index(currentIndex.x-signum(deltaX),currentIndex.y))) //可以x方向远离
        {
            if(deltaX>0)
            {
                currentChess->move(Qt::Key_A);
            }
            else
            {
                currentChess->move(Qt::Key_D);
            }
//            moved=true;

            return;
        }
    }
    if(signum(deltaY)!=0)
    {
        if(canBeMovedTo(Index(currentIndex.x,currentIndex.y-signum(deltaY)))) //可以x方向远离
        {
            if(deltaY>0)
            {
                currentChess->move(Qt::Key_W);
            }
            else
            {
                currentChess->move(Qt::Key_S);
            }
//            moved=true;

            return;
        }
    }
}

void GameController::autoAttack()
{
    if(hasEnemyToAutoAttack())
    {
//        attackActed=true;
        Chess *targetChess=findTheNearestEnemy();
        actAttack(currentChess,targetChess);
    }
}

Chess* GameController::findTheNearestEnemy()
{
    Chess *returnChess, *tempChess;
    int minDistance=10000;
    foreach(tempChess,blueTeamChesses)
    {
        if(currentChess->distanceTo(*tempChess) < minDistance)
        {
            minDistance=currentChess->distanceTo(*tempChess);
            returnChess=tempChess;
        }
    }
    return returnChess;
}

bool GameController::canBeMovedTo(Index indexAfterMove)
{
    //不能出边界
    if(!indexAfterMove.isValid())
    {
        return false;
    }
    //不能撞墙
    if(colorsOfMaps[currentStage][5*indexAfterMove.y+indexAfterMove.x]==Qt::black)
    {
        return false;
    }
    //不能撞人
    Chess *tempChess;
    foreach(tempChess,blueTeamChesses)
    {
        if(tempChess->index()==indexAfterMove)
        {
            return false;
        }
    }
    foreach(tempChess,redTeamChesses)
    {
        if(tempChess->index()==indexAfterMove)
        {
            return false;
        }
    }
    return true;
}

int GameController::signum(int x)
{
    if(x>0)
    {
        return 1;
    }
    if(x<0)
    {
        return -1;
    }
    return 0;
}

void GameController::initReadTeam(int stage)
{
    if(stage==0) //第一关
    {
        Chess *newTankChess,*newAssassinChess,*newArcherChess;
        newTankChess=new TankChess(Index(3,2),true);
        redTeamChesses<<newTankChess;

        newAssassinChess=new AssassinChess(Index(3,0),true);
        redTeamChesses<<newAssassinChess;

        newArcherChess=new ArcherChess(Index(4,0),true);
        redTeamChesses<<newArcherChess;
    }
    else //第二关
    {
        Chess *newBossChess=new BossChess(Index(2,1));
        redTeamChesses<<newBossChess;
    }
}

void GameController::restart(int stage)
{
    blueTeamChesses.clear();
    redTeamChesses.clear();
    initReadTeam(stage);
    chessesHasSetted=0;
    currentStage=stage;
    currentChess=nullptr;
    moved=true;
    attackActed=true;

}


