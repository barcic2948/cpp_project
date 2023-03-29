#include "custom_text.h"

Custom_Text::Custom_Text(float x, float y, int charSize, std::string text,  sf::Color color, sf::Font &font) {
    this->custom_text = new sf::Text();
    custom_text->setFont(font);
    custom_text->setString(text);
    custom_text->setCharacterSize(charSize);
    custom_text->setPosition(sf::Vector2f(x, y));
    custom_text->setFillColor(color);
}

Custom_Text::~Custom_Text() {
    delete this->custom_text;
    std::cout << "Removed Text!" << std::endl;
}

void Custom_Text::draw(sf::RenderWindow* window) {
    window->draw(*custom_text);
}