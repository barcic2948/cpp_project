#pragma once

#ifndef OHG_GAME_H
#define OHG_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "generic_game.h"

class Game : public GenericGame {
    
    protected:
        
        
    public:
        Game(int x, int y, std::string title);
        ~Game();
        void run() override;
};

#endif
