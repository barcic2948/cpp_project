#pragma once

#ifndef CUSTOM_TEXT_H
#define CUSTOM_TEXT_H

#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

class Custom_Text {
    protected:
        sf::Text custom_text;
        std::string custom_font_path = "C:\\Users\\barci\\Desktop\\cpp_project\\fonts\\CenturyGothic.ttf"; //"C:\\Users\\barci\\Desktop\\cpp_project\\fonts\\arial.ttf";
        sf::Font custom_font;
    public:
        Custom_Text(std::string text, int charSize, int x, int y, sf::Color color);
        ~Custom_Text();
        void draw(sf::RenderWindow* window);
        void align_center();
        void align_left();
        void align_right();
        void set_bold(bool value);
        void set_underline(bool value);
};

#endif