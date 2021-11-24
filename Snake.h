//
// Created by rodion on 17.11.2021.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "ObjectView.h"
#include <QBrush>

#include <QEvent>
#include <QApplication>
#include <QPainter>
#include "Square.h"
#include "GameView.h"
#include "Food/Food.h"
#include "CriticalFailEvent.h"


class Snake : public ObjectView {
public:
    enum Direction {
        left, rigth, down, up
    };


    Direction _way;
    QVector<QPoint> _snake_cells;
    QBrush *_head = new QBrush(Qt::red, Qt::SolidPattern);
    QBrush *_body = new QBrush(Qt::green, Qt::SolidPattern);

    GameView *_context;

    Snake(GameView *context, QPoint begin, Direction start, QBrush *head, QBrush *body) : _context(context),
                                                                                          _way(start), _head(head),
                                                                                          _body(body) {
        _snake_cells.push_back(begin);
    }

    Snake(GameView *context, QPoint begin, Direction start) : _context(context), _way(start) {
        _snake_cells.push_back(begin);
    }


    virtual void setListen() = 0;

    virtual void killListen() = 0;

    virtual void critical_event() {
        QApplication::sendEvent(_context, new CriticalFailEvent());
    }

    virtual void next_step() {
        QPoint new_head(_snake_cells[0]);

        switch (_way) {
            case rigth:
                new_head.setX(new_head.x() + 1);
                break;
            case left:
                new_head.setX(new_head.x() - 1);
                break;
            case down:
                new_head.setY(new_head.y() + 1);
                break;
            case up:
                new_head.setY(new_head.y() - 1);
                break;
        }
        if (new_head.x() < 0 || new_head.y() < 0) {
            critical_event();
            return;
        }
        if (new_head.x() >= _context->get_count_point_side() || new_head.y() >= _context->get_count_point_side()) {
            critical_event();
            return;
        }


        _snake_cells.push_front(new_head);
        _snake_cells.pop_back();
        check_head_on_body();
    };


    void painObject(QPainter &qPainter) override {
        if (qPainter.isActive()) {
            qPainter.setBrush(*_head);
            Square(_snake_cells[0], _context->get_size_edge()).painObject(qPainter);
            qPainter.setBrush(*_body);
            for (int i = 1; i < _snake_cells.size(); i++) {
                Square(_snake_cells[i], _context->get_size_edge()).painObject(qPainter);
            }
            qPainter.setBrush(Qt::NoBrush);
        }
    }

    QVector<QPoint> getCells() const {
        return _snake_cells;
    }

    QPoint get_head() {
        return _snake_cells.first();
    }

    virtual void increase_snake(QPoint fruit) {
        _snake_cells.push_front(fruit);
    };
    virtual bool is_eating_fruit(Food& food){
        if (get_head()==food.getField()){
            increase_snake(food.getField());
            return true;
        }
        else
            return false;
    }

    virtual void check_intersection(Snake &snake) {
        for (QPoint cell: _snake_cells) {
            for (QPoint cellarg: snake.getCells()) {
                if (cell == cellarg) {
                    critical_event();
                    return;
                }

            }
        }
    };

    virtual void change_way(Direction direction) {
        if ((direction == left && _way == rigth) || (direction == rigth && _way == left))
            critical_event();
        if ((direction == down && _way == up) || (direction == up && _way == down))
            critical_event();

        _way = direction;

    };

    virtual void check_head_on_body() {
        if (_snake_cells.count(get_head()) > 1) {
            critical_event();
        }
    }


};


#endif //SNAKE_SNAKE_H
