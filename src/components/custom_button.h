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
public:
    Custom_Button(float x, float y, float width, float height, sf::Font &font, std::string _text, sf::Color text_color, sf::Color button_color);
    ~Custom_Button();
    void draw(sf::RenderWindow *window);
};


#endif