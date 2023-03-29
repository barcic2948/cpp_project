#include "src/game.h"


int main()
{  
    Game tgame;
    if(tgame.init()) {
        tgame.mainMenu();
    }
    return 0;
}