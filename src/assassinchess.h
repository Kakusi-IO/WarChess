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
signals:

};

#endif // ASSASSINCHESS_H
