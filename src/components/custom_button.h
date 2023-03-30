#pragma once

#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "custom_text.h"

class Custom_Button
{
private:
    sf::RectangleShape *shape;
    sf::Text *text;
    sf::Color button_color;
    sf::Color hover_color;
public:
    Custom_Button(float x, float y, float width, float height,
        sf::Font &font, std::string _text, sf::Color text_color, int char_size,
        sf::Color _button_color, sf::Color _hover_color
    );
    ~Custom_Button();
    void draw(sf::RenderWindow *window);

    bool update(const sf::Vector2i mouse_position);
};


#endif