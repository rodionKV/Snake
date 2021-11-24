#include <iostream>
#include "GameViewUsual.h"
#include<QApplication>
#include "Food/Food.h"
#include "SnakeUser.h"
#include <QIcon>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    QApplication::setWindowIcon(QIcon(R"(C:\Users\rodion\Documents\Ubuntu_servel_file\snake\images\snake.png)"));
    GameViewUsual game(13);

    game.show();
    game.start_play();

    return app.exec();
}
