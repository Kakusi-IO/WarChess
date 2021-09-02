#ifndef CHESS_H
#define CHESS_H

#include "index.h"
#include "includedLibs.h"
#include <QObject>

class Chess : public QObject
{
    Q_OBJECT
    friend class GameController;
    friend class GameWindow;
protected:
    int hitPoint; //生命值
    int attackValue; //攻击力
    int stepLength; //步长
    int attackDistance; //攻击距离
    QString pixmapPath; //图片路径
    Index placeIndex;
    bool alive=true;
public:
    explicit Chess(QObject *parent = nullptr);
    Chess(Index);
    virtual int attack();
    virtual void beAttacked(int);
    virtual void death();
    Index index() const;
    QString info() const;
    void move(int);
    double distanceTo(const Chess& rhs) const;

    virtual QString chessName() const;

signals:

};

#endif // CHESS_H
