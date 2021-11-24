//
// Created by rodion on 24.11.2021.
//

#ifndef SNAKE_GAMEVIEW_H
#define SNAKE_GAMEVIEW_H
#include <QWidget>

#include "CriticalFailEvent.h"
#include <QSound>

class GameView:public QWidget{
private:
   // QSound backround_sound;
    QString path_music_back_round=R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\sounds\backround.wav)";
    const int DOT_NUM;
    const int FEILD_EDGE;
public:
//    GameView(int dot_num,int field_edge):DOT_NUM(dot_num),FEILD_EDGE(field_edge), backround_sound(path_music_back_round){
//
//    }
    GameView(int dot_num,int field_edge):DOT_NUM(dot_num),FEILD_EDGE(field_edge){
//        QSound qsound(R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\sounds\backround.wav)");
//        qsound.play();
    }
//    virtual void start_play_music(){
//        backround_sound.setLoops(-1);
//        backround_sound.play();
//    }
//    virtual void stop_play_music(){
//        backround_sound.stop();
//    }
    virtual void init_list_food(int count_food) = 0;
    virtual int get_count_point_side(){
        return DOT_NUM;
    };
    virtual int get_size_edge(){
        return FEILD_EDGE;
    }
    virtual void next_frame()=0;
    virtual void paint(QPainter& qPainter)=0;
    virtual bool is_playing()=0;
    virtual void start_play()=0;
    virtual void pause_play()=0;
   // virtual void restart_play()=0;
    virtual void win_event(){
        QMessageBox msgBox;
        msgBox.setText("Congratulations!!!");
        // msgBox.setInformativeText("You win :-) \nWant to start the game again?");
        msgBox.setInformativeText("You win :-)");
      //  msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::NoIcon);
        msgBox.setDefaultButton(QMessageBox::Ok);
        pause_play();
        int res = msgBox.exec();

        if (res == QMessageBox::Ok) {
           // restart_play();
           close();}


    };
    virtual void fail_event(){
        QMessageBox msgBox;
        msgBox.setText("Please read carefully!");
       // msgBox.setInformativeText("You lose :-( \nWant to start the game again?");
        msgBox.setInformativeText("You lose :-( ");
        msgBox.setStandardButtons(QMessageBox::Ok );
        //msgBox.setIcon(QMessageBox::Critical);
        msgBox.setDefaultButton(QMessageBox::Ok);
        pause_play();
        int res = msgBox.exec();

        if (res == QMessageBox::Ok) {
         //   restart_play();
         close();
        }

    };
    bool event(QEvent *ev) override{
        if (ev->type()==CriticalFailEvent::CodeFailEvent){
             fail_event();
            return true;
        }
        return QWidget::event(ev);
    }




};

#endif //SNAKE_GAMEVIEW_H
