#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    blueTeamChesses.clear();
    redTeamChesses.clear();
}

void GameController::addChess(Chess * newChess)
{
    blueTeamChesses<<newChess;
}
