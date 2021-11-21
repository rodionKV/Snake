//
// Created by rodion on 19.11.2021.
//

#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H
#include <QPoint>
class Point{
private:
    int _x, _y;
public:
    Point(int x , int y):_x(x),_y(y){

    }
operator QPoint(){
    return QPoint(_x,_y);
    }

    int& getX(){
        return _x;
    }
    int& getY(){
        return _y;
    }
};
#endif //SNAKE_POINT_H
