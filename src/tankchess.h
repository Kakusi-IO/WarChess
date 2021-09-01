#ifndef TANKCHESS_H
#define TANKCHESS_H

#include "chess.h"
#include "globaldefination.h"
#include <QObject>

class TankChess : public Chess
{
    Q_OBJECT
public:
//    explicit TankChess(QObject *parent = nullptr);
    TankChess(Index,QObject *parent=0);
    void beAttacked(int) override;

signals:

};

#endif // TANKCHESS_H
