#include <iostream>
#include "Game.h"
#include<QApplication>
#include "Food/Food.h"
#include "SnakeUser.h"
#include <QIcon>
using namespace std;
//TODO:Исправить рисование Food
//Написать константы конфигурации
//Сделать правильную модификацию  Food


int main(int argc,char* argv[])
{


    QApplication app(argc,argv);
    QApplication::setWindowIcon(QIcon(R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\images\snake.png)"));

    Game game;
    game.show();
    game.start_play();

    game.repaint();

    return app.exec();
}
