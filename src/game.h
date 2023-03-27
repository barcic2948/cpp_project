#pragma once

#ifndef OHG_GAME_H
#define OHG_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "generic_game.h"
#include "text/custom_text.h"

class Game : public GenericGame {
    
    protected:
        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;
    public:
        Game(int x, int y, std::string title);
        ~Game();
        void run() override;
        void mainMenu();
        void pouseMenu();
};

#endif
