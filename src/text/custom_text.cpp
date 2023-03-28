#include "custom_text.h"
#include <iostream>

Custom_Text::Custom_Text(std::string text, int charSize, int x, int y, sf::Color color) {

    if (!this->custom_font.loadFromFile(this->custom_font_path)) {}
    else {
        std::cout<<"Read font from file."<<std::endl;
    }
    this->custom_text.setFont(custom_font);
    this->custom_text.setString(text);
    this->custom_text.setCharacterSize(charSize);
    this->custom_text.setPosition(x, y);
    this->custom_text.setFillColor(color);
}

Custom_Text::~Custom_Text() {

}

void Custom_Text::draw(sf::RenderWindow* window) {
    window->draw(this->custom_text);
}

void Custom_Text::align_center() {
    this->custom_text.setOrigin(this->custom_text.getLocalBounds().left + this->custom_text.getLocalBounds().width / 2, this->custom_text.getLocalBounds().top + this->custom_text.getLocalBounds().height / 2);
}

void Custom_Text::align_left() {
    this->custom_text.setOrigin(-10, this->custom_text.getLocalBounds().top + this->custom_text.getLocalBounds().height / 2);
}

void Custom_Text::align_right() {
    this->custom_text.setOrigin(this->custom_text.getLocalBounds().left + this->custom_text.getLocalBounds().width + 10, this->custom_text.getLocalBounds().top + this->custom_text.getLocalBounds().height / 2);
}

void Custom_Text::set_bold(bool value) {
    this->custom_text.setStyle(value ? sf::Text::Bold : sf::Text::Regular);
}

void Custom_Text::set_underline(bool value) {
    this->custom_text.setStyle(value ? sf::Text::Underlined : sf::Text::Regular);
}