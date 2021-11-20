#include <iostream>
#include "Game.h"
#include<QApplication>
#include "Food/Food.h"
#include "SnakeUser.h"
using namespace std;

int main(int argc,char* argv[])
{


    QApplication app(argc,argv);

    Game game;



    game.show();

    game.repaint();

    return app.exec();
}
