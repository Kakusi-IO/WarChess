#ifndef INDEX_H
#define INDEX_H

#include <cmath>
#include <QPoint>
#include <QDebug>

struct Index{
    int x;
    int y;
    static Index pointToIndex(QPoint point)
    {
        Index retIndex;
        retIndex.x=(point.x()-50)/100;
        retIndex.y=(point.y()-50)/100;
        return retIndex;
    }
    static Index moveTo(Index index,int key)
    {
        switch(key)
        {
        case Qt::Key_W:
            index.y--;
            break;
        case Qt::Key_S:
            index.y++;
            break;
        case Qt::Key_A:
            index.x--;
            break;
        case Qt::Key_D:
            index.x++;
            break;
        }
        return index;
    }
    Index()=default;
    Index(int x_,int y_): x(x_),y(y_) {}

    //棋子在地图内
    bool isValid() const
    {
        if(x<0||x>4||y<0||y>4)
        {
            return false;
        }
        return true;
    }

    //棋子在蓝色半区
    bool isValidForGameOne() const
    {
        if(!isValid())
        {
            return false;
        }
        if(y<=x)
        {
            return false;
        }
        return true;
    }
    bool isValidForGameTwo() const
    {
        if(!isValid())
        {
            return false;
        }
        if(y<3)
        {
            return false;
        }
        return true;
    }
    bool operator== (const Index& rhs)
    {
        return x==rhs.x&&y==rhs.y;
    }
    static double distance(const Index& lhs,const Index& rhs)
    {
        double squareOfDistance=(lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y);
//        qDebug()<<sqrt(squareOfDistance);
        return sqrt(squareOfDistance);
    }
};






#endif // INDEX_H
