#pragma once

#ifndef GENERICGAME_H
#define GENERICGAME_H

#include <SFML/Graphics.hpp>

class GenericGame{
    protected:
        /**
         * @brief Game window
         * 
         */
        sf::RenderWindow *window;
    public:
        /**
         * @brief Runs the base game
         * 
         */
        virtual void run()=0;
};

#endif
