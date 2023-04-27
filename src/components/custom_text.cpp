#include "custom_text.h"
#include "component.h"

Custom_Text::Custom_Text(float x, float y, std::string _text, sf::Font &font, int _char_size, sf::Color *_text_color) {
    this->text = new sf::Text();
    this->text->setPosition(x,y);
    this->text->setFont(font);
    this->text->setFillColor(*_text_color);
    this->text->setString(_text);
    this->text->setCharacterSize(_char_size);
}

Custom_Text::~Custom_Text() {
    //std::cout << "Removed Text" << std::endl;
    delete this->text;
}

void Custom_Text::draw(sf::RenderWindow *window) {
    window->draw(*this->text);
}

void Custom_Text::update(sf::RenderWindow *window) {
    //std::cout << "update" << std::endl;
}