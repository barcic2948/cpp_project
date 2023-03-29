#include "custom_button.h"

Custom_Button::Custom_Button(float x, float y, float width, float height, sf::Font &font, std::string _text, sf::Color text_color, sf::Color button_color) {

    this->shape = new sf::RectangleShape();
    shape->setPosition(sf::Vector2f(x, y));
    shape->setSize(sf::Vector2f(width, height));
    shape->setFillColor(button_color);

    this->text = new sf::Text();
    text->setFont(font);
    text->setFillColor(text_color);
    text->setCharacterSize(30);
    text->setString(_text);
    text->setPosition(
        x + (width - text->getLocalBounds().width) / 2.f - text->getLocalBounds().left,
        y + (height - text->getLocalBounds().height) / 2.f - text->getLocalBounds().top
    );
    
    
}

Custom_Button::~Custom_Button() {
    delete this->shape;
    delete this->text;
    std::cout << "Removed Button" << std::endl;
}

void Custom_Button::draw(sf::RenderWindow* window) {
    window->draw(*shape);
    window->draw(*text);
}