//
// Created by rodion on 21.11.2021.
//

#ifndef SNAKE_PEACH_H
#define SNAKE_PEACH_H
#include <QString>
#include <QPoint>
class Peach:public Food{
public:
    QString path_pic=R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\images\peach.png)";
  //  explicit Peach( Square field): Food(field,path_pic){}
    explicit Peach( QPoint qPoint,int size_edge): Food(qPoint,size_edge,path_pic){}

};
#endif //SNAKE_PEACH_H
