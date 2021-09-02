#ifndef ASSASSINCHESS_H
#define ASSASSINCHESS_H

#include "chess.h"
#include <QObject>

class AssassinChess : public Chess
{
    Q_OBJECT
public:
    //explicit AssassinChess(QObject *parent = nullptr);
    AssassinChess(Index,QObject *parent=0);
    AssassinChess(Index,bool,QObject *parent=0);
    QString chessName() const override;
signals:

};

#endif // ASSASSINCHESS_H
