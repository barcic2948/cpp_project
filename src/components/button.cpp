#include "component.h"
#include "button.h"

Button::Button(float x, float y, float width, float height, std::string _text, sf::Font &font, int _char_size,
 sf::Color *_button_color, sf::Color *_text_color, sf::Color *_hover_color) {
    this->button_color = _button_color;
    this->hover_color = _hover_color;

    this->shape = new sf::RectangleShape();
    this->shape->setFillColor(*this->button_color);
    this->shape->setPosition(x, y);
    this->shape->setSize(sf::Vector2f(width, height));

    this->text = new sf::Text();
    this->text->setFont(font);
    this->text->setCharacterSize(_char_size);
    this->text->setString(_text);
    this->text->setFillColor(*_text_color);
    this->text->setPosition(x + (width - text->getLocalBounds().width) / 2.f - text->getLocalBounds().left,
     y + (height - text->getLocalBounds().height) / 2.f - text->getLocalBounds().top);
}

Button::~Button() {
    delete this->text;
    delete this->shape;
    std::cout << "Removed Button" << std::endl;
}

void Button::draw(sf::RenderWindow *window) {
    window->draw(*shape);
    window->draw(*text);
}

void Button::update(sf::RenderWindow *window) {
    if (shape->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)))) {
        shape->setFillColor(*this->hover_color);
        this->is_hover = true;
    }
    else {
        shape->setFillColor(*this->button_color);
        this->is_hover = false;
    }
}

bool Button::getHover() {
    return this->is_hover;
}