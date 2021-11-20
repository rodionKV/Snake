//
// Created by rodion on 17.11.2021.
//

#ifndef SNAKE_SQUARE_H
#define SNAKE_SQUARE_H

#include "ObjectView.h"
#include "Point.h"

class Square : public ObjectView {
private:
    Point _down, _up;

public:
    Square(Point down, Point up) : _down(down), _up(up) {}
    Square(QPoint qPoint,int size_edge): _down(Point(qPoint.x()*size_edge,qPoint.y()*size_edge)), _up(Point((qPoint.x()+1)*size_edge,(qPoint.y()+1)*size_edge)){
    }

    Square(Point down, int size_edge) : _down(down), _up(Point(down.getX() + size_edge, down.getY() + size_edge)) {}

    Square(int x_down, int y_down, int x_up, int y_up) : _down(Point(x_down, y_down)), _up(Point(x_up, y_up)) {}

    std::vector<Point> get_all_points() {
        int size_edge = _down.getX() - _up.getX();
        std::vector<Point> result;
        result.push_back(_down);
        result.push_back(*new Point(_down.getX()+size_edge,_down.getY()));
        result.push_back(_up);
        result.push_back(*new Point(_down.getX(),_down.getY()+size_edge));
        return result;
    }

    void painObject(QPainter &qPainter) override {
        if (qPainter.isActive()) {
            int size_edge = _down.getX() - _up.getX();
            qPainter.drawRect(_down.getX(),_down.getY(),size_edge,size_edge);
        }
    }
};

#endif //SNAKE_SQUARE_H
