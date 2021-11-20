//
// Created by rodion on 17.11.2021.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include <QPainter>
#include "../ObjectView.h"
#include "../Square.h"

class Food : public ObjectView {
private:
    Square &_field;
    std::string _path_picture;

    Food(Square &field, std::string &path_picture) : _field(field), _path_picture(path_picture) {

    }

    void painObject(QPainter &) override ;

// void createObject() override{
//
// };
// void erasureObject() override{
//
// };
    Square& getField() {
        return _field;
    }

    std::string getPathPicture() {
        return _path_picture;
    }
};

#endif //SNAKE_FOOD_H
