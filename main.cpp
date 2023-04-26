#include "src/game.h"

int main() {  
    Game tgame;
    if(tgame.init()) {
        tgame.run();
    }
    return 0;
}