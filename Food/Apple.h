//
// Created by rodion on 19.11.2021.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H
#include "Food.h"
#include <iostream>
#include <QString>
class Apple:public Food{
public:
    QString path_pic=R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\images\apple.png)";
    explicit Apple( Square& field): Food(field,path_pic){}
};
#endif //SNAKE_APPLE_H
