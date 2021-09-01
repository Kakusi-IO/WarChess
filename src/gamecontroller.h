#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "chess.h"
#include <QObject>
#include <QList>

class GameController : public QObject
{
    Q_OBJECT
    friend class GameWindow;

    QList<Chess*>blueTeamChesses;
    QList<Chess*>redTeamChesses;
    int currentStage=1; //当前的关卡数，取值为1或2
public:
    explicit GameController(QObject *parent = nullptr);
    void addChess(Chess*);
signals:

};

#endif // GAMECONTROLLER_H
