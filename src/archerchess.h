#ifndef ARCHERCHESS_H
#define ARCHERCHESS_H

#include "chess.h"
#include <QObject>

class ArcherChess : public Chess
{
    Q_OBJECT
public:
    explicit ArcherChess(QObject *parent = nullptr);

signals:

};

#endif // ARCHERCHESS_H
