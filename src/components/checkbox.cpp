#include "checkbox.h"

Checkbox::Checkbox(bool _state, float x, float y, float width, float height, sf::Color *_box_color) {
    this->box_color = _box_color;
    this->state = _state;

    this->box = new sf::RectangleShape();
    this->box->setFillColor(*this->box_color);
    this->box->setPosition(x, y);
    this->box->setSize(sf::Vector2f(width, height));

    this->inside = new sf::RectangleShape();
    this->inside->setFillColor(this->state ? *this->box_color : sf::Color::Black);
    this->inside->setPosition(x + 5, y + 5);
    this->inside->setSize(sf::Vector2f(width - 10, height - 10));
}

Checkbox::~Checkbox() {
    delete this->box;
    delete this->inside;
}

void Checkbox::update(sf::RenderWindow *window) {
    if (box->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)))) {
        this->is_hover = true;
    }
    else {
        this->is_hover = false; 
    }
    this->inside->setFillColor(this->state ? *this->box_color : sf::Color::Black);
}

void Checkbox::draw(sf::RenderWindow *window) {
    window->draw(*this->box);
    window->draw(*this->inside);
}


const bool Checkbox::getHover() {
    return this->is_hover;
}