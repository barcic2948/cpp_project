#pragma once

#ifndef GAME_H
#define GAME_H

#include "generic_game.h"
#include "components/component.h"
#include "components/custom_text.h"
#include "components/button.h"

class Game : public GenericGame {
    
    protected:
        const unsigned int window_width = 1000;
        const unsigned int window_height = 700;
        sf::Font font;
        const std::string font_path = "C:\\Users\\barci\\Desktop\\git\\cpp_project\\fonts\\CenturyGothic.ttf";

        sf::Color *gate_color = new sf::Color(76, 76, 76, 255);
        sf::Color *text_color = new sf::Color(254, 254, 254, 255);
        sf::Color *hover_color = new sf::Color(100, 100, 100, 255);

        std::vector<Component*> game_elements;
        std::vector<Component*> game_elements_sim;

        void main_menu();
        void play();
        void options();
        void pouse_menu();
        void clear();
    
    public:
        Game();
        ~Game();
        bool init();
        void run() override;
};

#endif