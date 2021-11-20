//
// Created by rodion on 17.11.2021.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "ObjectView.h"
#include <QBrush>
#include <iostream>
#include <QEvent>
#include <QApplication>
#include <QPainter>
#include "Square.h"

class Snake : public ObjectView {
public:
    enum Direction {
        left, rigth, down, up
    };
    Direction _way;
    QVector<QPoint> _snake_cells;
    QBrush _head, _body;
    QObject &_context;

    Snake(QObject &context, QPoint begin, Direction start, QBrush &head, QBrush &body) : _context(context),
                                                                                          _way(start), _head(head),
                                                                                          _body(body) {
        _snake_cells.push_back(begin);
    }


    virtual void setListen() = 0;

    virtual void next_step() {
        QPoint new_head(_snake_cells[0]);

        switch (_way) {
            case rigth:
                new_head.setX(new_head.x() - 1);
                break;
            case left:
                new_head.setX(new_head.x() + 1);
                break;
            case down:
                new_head.setY(new_head.y() - 1);
                break;
            case up:
                new_head.setY(new_head.y() + 1);
                break;
        }
        _snake_cells.push_front(new_head);
    };


    void painObject(QPainter &qPainter) override {
        if (qPainter.isActive()) {
            qPainter.setBrush(_head);
            Square(_snake_cells[0],20).painObject(qPainter);
            qPainter.setBrush(_body);
            for (int i = 1; i < _snake_cells.size(); ++i) {
                Square(_snake_cells[i],20).painObject(qPainter);
            }
            qPainter.setBrush(Qt::NoBrush);
        }
    }

    QVector<QPoint> getCells() const {
        return _snake_cells;
    }


    virtual void increase_snake(QPoint) {

    };

    virtual void check_intersection(Snake &snake) {
        for (QPoint cell: _snake_cells) {
            for (QPoint cellarg: snake.getCells()) {
                if (cell == cellarg) {
                    QApplication::sendEvent(&_context, new FailEvent());
                    return;
                }

            }
        }
    };

    virtual void change_way(Direction direction) {
        if ((direction == left && _way == rigth) || (direction == rigth && _way == left))
            QApplication::sendEvent(&_context, new FailEvent());
        if ((direction == down && _way == up) || (direction == up && _way == down))
            QApplication::sendEvent(&_context, new FailEvent());

        _way = direction;

    };

    class FailEvent : public QEvent {
    public:
        static const int CodeFailEvent = QEvent::User + 200;

        FailEvent() : QEvent((Type)(CodeFailEvent)) {

        }

        QString info() {
            return "FailStep!";
        }

    };
};


#endif //SNAKE_SNAKE_H
