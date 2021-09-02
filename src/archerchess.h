#ifndef ARCHERCHESS_H
#define ARCHERCHESS_H

#include "chess.h"
#include <QObject>

class ArcherChess : public Chess
{
    Q_OBJECT
public:
    //explicit ArcherChess(QObject *parent = nullptr);
    ArcherChess(Index,QObject* parent=nullptr);
    QString chessName() const override;
signals:

};

#endif // ARCHERCHESS_H
