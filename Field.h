//
// Created by rodion on 19.11.2021.
//

#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H

#include "ObjectView.h"

#include <vector>
#include "Square.h"
#include <QPainter>

class Field : public ObjectView {
private:
    int _num_x, _num_y;
    std::vector<std::vector<Square>> field;
public:
    Field(int num_x, int num_y, int size_edge):_num_x(num_x),_num_y(num_y) {
        field.resize(num_y);
        for (int i = 0; i < num_y; ++i) {
            for (int j = 0; j < num_x; ++j) {
                field[i].push_back(*(new Square(QPoint(j,i),size_edge)));
            }

        }
    }
Field(){};
    void painObject(QPainter &qPainter) override {
        if (qPainter.isActive()) {
            for (int i = 0; i < _num_x; i++) {
                for (int j = 0; j < _num_y; j++) {
                    switch ((i + j) % 2) {
                        case 1:
                            qPainter.setBrush(QBrush(Qt::black, Qt::Dense7Pattern));
                            break;
                        case 0:
                            qPainter.setBrush(Qt::NoBrush);
                            break;

                    }
                    field[i][j].painObject(qPainter);
                }
            }
            qPainter.setBrush(Qt::NoBrush);
        }

    }

};

#endif //SNAKE_FIELD_H
