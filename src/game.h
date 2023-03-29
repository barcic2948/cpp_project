#pragma once

#ifndef OHG_GAME_H
#define OHG_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "generic_game.h"
#include "components/custom_text.h"
#include "components/custom_button.h"

class Game : public GenericGame {
    
    private:
        std::string font_path = "C:\\Users\\barci\\Desktop\\cpp_project\\fonts\\CenturyGothic.ttf";

    protected:
        int WINDOW_WIDTH = 1000;
        int WINDOW_HEIGHT = 1000;
        sf::Font font;
        
    public:
        Game();
        ~Game();
        bool init();
        void run() override;
        void mainMenu();
        void pouseMenu();
};

#endif
