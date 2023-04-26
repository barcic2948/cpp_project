#pragma once

#include "component.h"

#ifndef CUSTOM_TEXT_H
#define CUSTOM_TEXT_H

class Custom_Text : public Component {
    protected:
        sf::Text *text;
    public:
        Custom_Text(float x, float y, std::string _text, sf::Font &font, int _char_size, sf::Color *_text_color);
        ~Custom_Text();
        void draw(sf::RenderWindow *window) override;
        void update(sf::RenderWindow *window) override;
};

#endif