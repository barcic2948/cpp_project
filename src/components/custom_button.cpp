#include "custom_button.h"

Custom_Button::Custom_Button(float x, float y, float width, float height,
        sf::Font &font, std::string _text, sf::Color text_color, int char_size,
        sf::Color _button_color, sf::Color _hover_color)
{
    this->button_color = _button_color;
    this->hover_color = _hover_color;

    this->shape = new sf::RectangleShape();
    shape->setPosition(sf::Vector2f(x, y));
    shape->setSize(sf::Vector2f(width, height));
    shape->setFillColor(_button_color);

    this->text = new sf::Text();
    text->setFont(font);
    text->setFillColor(text_color);
    text->setCharacterSize(char_size);
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

bool Custom_Button::update(const sf::Vector2i mouse_position) {
    if (shape->getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_position))) {
        shape->setFillColor(this->hover_color);
        return true;
    }
    shape->setFillColor(this->button_color);
    return false;   
}

void Custom_Button::center() {
    text->setPosition(shape->getPosition().x - ((text->getLocalBounds().width + text->getLocalBounds().left) / 2), this->text->getPosition().y);
    shape->setPosition(shape->getPosition().x - ((shape->getLocalBounds().width + shape->getLocalBounds().left) / 2), this->shape->getPosition().y);
}