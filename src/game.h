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
        std::string font_path = "/home/ltafker/Desktop/code/cpp_project/fonts/CenturyGothic.ttf";

    protected:
        int WINDOW_WIDTH = 1000;
        int WINDOW_HEIGHT = 700;
        sf::Font font;


        sf::Color color_background = sf::Color(30, 60, 70, 255);
        sf::Color color_button = sf::Color(50, 50, 50, 255);
        sf::Color color_button_on = sf::Color(100, 100, 100, 255);

        
    public:
        Game();
        ~Game();
        bool init();
        void run() override;
        void mainMenu();
        void pouseMenu();
};

#endif
