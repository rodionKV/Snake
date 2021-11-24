//
// Created by rodion on 17.11.2021.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include "../Square.h"

class Food : public ObjectView {
public:
    QPoint _field;
    int _size_of_edge;
    QString& _path_picture;

    Food(QPoint& field,int size_of_edge, QString &path_picture) : _field(field), _path_picture(path_picture),_size_of_edge(size_of_edge) {
    }

    void painObject(QPainter & qPainter) override {
        if( qPainter.isActive()){
                qPainter.drawPixmap((QRect)(Square(_field,_size_of_edge)),QPixmap(_path_picture));
        }
    }

    QPoint& getField() {
        return _field;
    }

   QString getPathPicture() {
        return _path_picture;
    }
};

#endif //SNAKE_FOOD_H
