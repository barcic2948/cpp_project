#pragma once

#include "component.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button : public Component {
    protected:
        sf::RectangleShape *shape;
        sf::Text *text;
        sf::Color *button_color;
        sf::Color *hover_color;
    public:
        bool is_hover;
        Button(float x, float y, float width, float height, std::string _text, sf::Font &font, int _char_size,
         sf::Color *_button_color, sf::Color *_text_color, sf::Color *_hover_color);
        ~Button();
        void draw(sf::RenderWindow *window) override;
        void update(sf::RenderWindow *window) override;
        const bool getHover();

};

#endif