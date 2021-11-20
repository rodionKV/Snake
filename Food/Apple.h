//
// Created by rodion on 19.11.2021.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H
#include "Food.h"
#include <iostream>
class Apple:public Food{
public:
    std::string path_pic=" ";
    Apple(Square field): Food(field,path_pic){}


};
#endif //SNAKE_APPLE_H
