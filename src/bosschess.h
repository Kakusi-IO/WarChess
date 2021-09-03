#ifndef BOSSCHESS_H
#define BOSSCHESS_H

#include "chess.h"
#include "index.h"
#include <QObject>

class BossChess : public Chess
{
    Q_OBJECT
public:
//    explicit BossChess(QObject *parent = nullptr);
    BossChess(Index,QObject *parent=0);


    QString chessName() const override;
signals:

};

#endif // BOSSCHESS_H
