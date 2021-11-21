//
// Created by rodion on 17.11.2021.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include <QPainter>
#include "../ObjectView.h"
#include "../Square.h"

class Food : public ObjectView {
public:
    Square &_field;
    QString& _path_picture;

    Food(Square &field, QString &path_picture) : _field(field), _path_picture(path_picture) {

    }

    void painObject(QPainter & qPainter) override {
        if( qPainter.isActive()){
                qPainter.drawPixmap((QRect)_field,QPixmap(_path_picture));
        }
    }

// void createObject() override{
//
// };
// void erasureObject() override{
//
// };
    Square& getField() {
        return _field;
    }

   QString getPathPicture() {
        return _path_picture;
    }
};

#endif //SNAKE_FOOD_H
