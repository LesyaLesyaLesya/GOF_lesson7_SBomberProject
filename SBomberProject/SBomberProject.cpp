
#include <conio.h>
#include <stdlib.h>
#include <memory>
#include "SBomber.h"                                                   
#include "MyTools.h"


using namespace std;

//========================================================================================================================
auto logger = std::make_shared<MyTools::ProxyLogger>(MyTools::FileLoggerSingleton::getInstance());

int main(void)
{
    
    logger->OpenLogFile("log.txt");

    //SBomber game{logger};
    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    logger->CloseLogFile();

    return 0;
}
