//
// Created by rodion on 20.11.2021.
//

#ifndef GAMEVIEW__H
#define GAMEVIEW__H
#include <QWidget>
#include <QFrame>
#include <QEvent>
#include <QPoint>
#include <QTimerEvent>
#include <QMessageBox>
#include <QSet>
#include <QTime>
#include "./Food/Apple.h"
#include "./Food/Peach.h"
#include "Field.h"
#include "SnakeUser.h"
#include "GameView.h"


#define       DOT_NUM 20


#define       FEILD_EDGE 40
#define       DELAY  300

class GameViewUsual : public GameView {
private:

    QVector<Food*> foods={new Apple(QPoint(0,0),FEILD_EDGE), new Peach(QPoint(DOT_NUM-1,DOT_NUM/2),FEILD_EDGE)};
    Field field;
    SnakeUser snake;
    bool playing = false;
    int timer_id = 0;

public:

    GameViewUsual() : GameView(DOT_NUM,FEILD_EDGE), field(DOT_NUM, FEILD_EDGE), snake(this) {
        this->setFixedSize(DOT_NUM * FEILD_EDGE, DOT_NUM * FEILD_EDGE);
        this->setWindowTitle("Snake");
        this->setCursor(Qt::BlankCursor);
    }
    explicit GameViewUsual(int count_food) : GameView(DOT_NUM,FEILD_EDGE),field(DOT_NUM, FEILD_EDGE), snake(this) {
        this->setFixedSize(DOT_NUM * FEILD_EDGE, DOT_NUM * FEILD_EDGE);
        this->setWindowTitle("Snake");
        this->setCursor(Qt::BlankCursor);
        foods.clear();
        foods.resize(count_food);
    }
    void init_list_food(int count_food) override{
        QTime time = QTime::currentTime();
        qsrand((uint) time.msec());
        QVector<QPoint> qp;

        foods.clear();
        for (int i = 0; i < count_food; ) {
            Food* newfood;
            QPoint newpoint(qrand()%DOT_NUM,qrand()%DOT_NUM);
            if (!qp.contains(newpoint)){
                i++;
                switch (qrand()%2) {
                    case 0:
                        newfood=new Apple(newpoint,FEILD_EDGE);
                        break;
                    case 1:
                        newfood=new Peach(newpoint,FEILD_EDGE);
                        break;
                }
            }

            qp.push_back(newpoint);
            foods.push_back(newfood);
        }
    }




void start_play() override{
    init_list_food(foods.size());
    playing = true;
    snake.setListen();
    timer_id = startTimer(DELAY);
   // start_play_music();
    }
    void pause_play() override{
        playing= false;
        snake.killListen();
        killTimer(timer_id);
      //  stop_play_music();
    }
//    void restart_play() override{
//        playing= true;
//        snake.setListen();
//
//        timer_id = startTimer(DELAY);
//    }
  bool is_playing() override{
      return playing;
    }



    void paintEvent(QPaintEvent *event) override {
        QPainter qPainter(this);
        if (!qPainter.isActive())
            qPainter.begin(this);
        paint(qPainter);
    }
    void next_frame() override{

        for (int i = 0; i < foods.length(); ++i) {
                if (snake.is_eating_fruit(*foods[i])){
                foods.remove(i);
                }
        }

        snake.next_step();
        this->repaint();
        if (foods.empty()){
            win_event();
        }
    }

    void paint(QPainter& qPainter) override{
        field.painObject(qPainter);
        snake.painObject(qPainter);
        for (Food *food: foods) {
            (*food).painObject(qPainter);
        }
    }

    void timerEvent(QTimerEvent *event) override {
        if (event->timerId() == timer_id) {
            if(playing){
             next_frame();
            }
        }
    }

};
#endif


