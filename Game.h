//
// Created by rodion on 20.11.2021.
//


#include <QWidget>
#include "SnakeUser.h"
#include "Field.h"
#include <QFrame>
#include <QEvent>
#include <QPoint>
#include <QTimerEvent>
#include "Food/Apple.h"
#include "Square.h"


#define       DOT_WIDTH 20
#define       DOT_HEIGTH 20
#define       FEILD_WIGTH 20
#define       FEILD_HEIGTH 20
#define       FEILD_EDGE 40
#define       DELAY  150

class Game : public QWidget {
private:
    Field field;
    SnakeUser snake;
    Apple  apple ;
    bool playing = false;
    int timer_id=0;
public:

    Game( ) :field(DOT_WIDTH,FEILD_WIGTH,FEILD_EDGE), snake(this), apple(Square(QPoint(1,3),FEILD_EDGE)){
        this->setFixedSize(DOT_WIDTH*FEILD_EDGE,DOT_HEIGTH*FEILD_EDGE);
        this->setWindowTitle("Snake");
        this->setCursor(Qt::BlankCursor);
        //this->setContentsMargins(QFrame::Box);
    }
void start_play(){
    timer_id= startTimer(DELAY);
    }
    void paintEvent(QPaintEvent *event) override{
        QPainter qPainter(this);
        if (! qPainter.isActive())
            qPainter.begin(this);
        field.painObject(qPainter);
        snake.painObject(qPainter);
        apple.painObject(qPainter);
    }

void timerEvent(QTimerEvent* event)override{
    if (event->timerId()==timer_id){
        snake.next_step();
        this->repaint();
    }
    }
};


