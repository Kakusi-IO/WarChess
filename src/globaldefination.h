#ifndef GLOBALDEFINATION_H
#define GLOBALDEFINATION_H

//#include <map>
//#include <string>
//using std::map;
//using std::string;
#include <QPoint>

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
    Index()=default;
    Index(int x_,int y_): x(x_),y(y_) {}
    bool isValid()
    {
        if(x<0||x>4||y<0||y>4)
        {
            return false;
        }
        return true;
    }
};

//namespace Constant {


//map<string,int> hitPoints={
//    {"Assassin",600},
//    {"Archer",500},
//    {"Tank",1200}
//};


//map<string,int> attackValues={
//    {"Assassin",80},
//    {"Archer",70},
//    {"Tank",50}
//};


//map<string,int> attackDistances={
//    {"Assassin",1},
//    {"Archer",3},
//    {"Tank",1}
//};


//map<string,int> stepLengths={
//    {"Assassin",2},
//    {"Archer",1},
//    {"Tank",1}
//};


//};

#endif // GLOBALDEFINATION_H
