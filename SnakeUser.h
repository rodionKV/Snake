//
// Created by rodion on 20.11.2021.
//

#ifndef SNAKE_SNAKEUSER_H
#define SNAKE_SNAKEUSER_H

#include "Snake.h"

#include <QKeyEvent>

#include <QBrush>




class SnakeUser : public Snake {
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
private:

    QBrush _head= QBrush(Qt::red, Qt::SolidPattern);
    QBrush _body= QBrush(Qt::green, Qt::SolidPattern);
    //QString _path_picture_head=R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\images\snake.png)";
    FilterKeys* filter= nullptr;
public:
    SnakeUser(GameView* context,QPoint begin, Direction start): Snake(context,begin,start,&_head,&_body){
    }
    explicit SnakeUser(GameView* context): Snake(context,*new QPoint(0,0),Direction::rigth,&_head,&_body) {

    }
    /*void painObject(QPainter &qPainter) override{
        if (qPainter.isActive()) {
            qPainter.setBrush(Qt::NoBrush);
            qPainter.drawPixmap((QRect)Square(_snake_cells[0],40),QPixmap(_path_picture_head));
            qPainter.setBrush(_body);
            for (int i = 1; i < _snake_cells.size(); i++) {
                Square(_snake_cells[i],20).painObject(qPainter);
            }
            qPainter.setBrush(Qt::NoBrush);
        }
    }*/



    void setListen() override {
        if (filter!= nullptr)
            killListen();
         filter = new FilterKeys(_context, dynamic_cast<Snake*>(this));
        (*_context).installEventFilter(filter);
    }
    void killListen() override{
        if(filter!= nullptr){
            (*_context).removeEventFilter(filter);
            delete filter;
            filter= nullptr;
        }

    }



};

#endif //SNAKE_SNAKEUSER_H
