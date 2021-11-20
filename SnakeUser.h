//
// Created by rodion on 20.11.2021.
//

#ifndef SNAKE_SNAKEUSER_H
#define SNAKE_SNAKEUSER_H

#include "Snake.h"

#include <QKeyEvent>

#include <QBrush>



class SnakeUser : public Snake {
private:

    QBrush _head= QBrush(Qt::red, Qt::Dense7Pattern);
    QBrush _body= QBrush(Qt::black, Qt::Dense7Pattern);
public:
    SnakeUser(QObject& context,QPoint begin, Direction start): Snake(context,begin,start,_head,_body)
                                                                  {
    }
SnakeUser(QObject &context): Snake(context,QPoint(0,0),Direction::rigth,_head,_body) {}


    void setListen() override {
        auto filter = new FilterKeys(&_context, dynamic_cast<Snake*>(this));
        _context.installEventFilter(filter);
    }

    class FilterKeys : public QObject {
    private:
        Snake *snake;
    protected:
        bool eventFilter(QObject *watched, QEvent *event) override {
            if (event->type() == QEvent::KeyPress) {
                int key = dynamic_cast<QKeyEvent *>(event)->key();
                switch (key) {
                    case Qt::Key_Left:
                        snake->change_way(Direction::left);
                        break;
                    case Qt::Key_Right:
                        snake->change_way(Direction::rigth);
                        break;

                    case Qt::Key_Down:
                        snake->change_way(Direction::down);
                        break;
                    case Qt::Key_Up:
                        snake->change_way(Direction::up);
                        break;
                    default:
                        break;

                }
                return true;
            }
            return false;
        }

    public:
        FilterKeys(QObject *pobj, Snake *snakeUser) : QObject(pobj), snake(snakeUser) {
        }
    };

};

#endif //SNAKE_SNAKEUSER_H
