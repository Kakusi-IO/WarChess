#ifndef TANKCHESS_H
#define TANKCHESS_H

#include "chess.h"
#include "index.h"
#include <QObject>

class TankChess : public Chess
{
    Q_OBJECT
public:
//    explicit TankChess(QObject *parent = nullptr);
    TankChess(Index,QObject *parent=0);
    void beAttacked(int) override;
    QString chessName() const override;
signals:

};

#endif // TANKCHESS_H
