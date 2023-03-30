#pragma once

#ifndef CUSTOM_TEXT_H
#define CUSTOM_TEXT_H

#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

class Custom_Text {
    protected:
        sf::Text *custom_text;
    public:
        Custom_Text(float x, float y, int charSize, std::string text, sf::Color color, sf::Font &font);
        ~Custom_Text();
        void draw(sf::RenderWindow* window);
        
};

#endif