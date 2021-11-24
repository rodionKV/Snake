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
    int _num_e;
    std::vector<std::vector<Square>> field;
public:
    Field(int num_e,int size_edge):_num_e(num_e) {
        field.resize(num_e);
        for (int i = 0; i < num_e; ++i) {
            for (int j = 0; j < num_e; ++j) {
                field[i].emplace_back(QPoint(j,i),size_edge);
            }

        }
    }
    void painObject(QPainter &qPainter) override {
        if (qPainter.isActive()) {
            for (int i = 0; i < _num_e; i++) {
                for (int j = 0; j < _num_e; j++) {
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
