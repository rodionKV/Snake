//
// Created by rodion on 20.11.2021.
//


#include <QWidget>
#include "SnakeUser.h"
#include "Field.h"



#define       DOT_WIDTH 20
#define       DOT_HEIGTH 20
#define       FEILD_WIGTH 20
#define       FEILD_HEIGTH 20
#define       FEILD_EDGE 20
#define       DELAY  150

class Game : public QWidget {
public:

    Game( ) {
        this->setFixedSize(QSize(DOT_WIDTH*FEILD_WIGTH,DOT_HEIGTH*FEILD_HEIGTH));
        this->setWindowTitle("Snake GameView");

    }

};


