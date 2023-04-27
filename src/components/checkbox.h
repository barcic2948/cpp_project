#pragma once

#include "component.h"

#ifndef CHECKBOX_H
#define CHECKBOX_H

class Checkbox : public Component {
    private:
        bool is_hover;
        sf::Color *box_color;
        sf::RectangleShape *box;
        sf::RectangleShape *inside;
    public:
        bool state;
        Checkbox(bool _state, float x, float y, float width, float height, sf::Color *_box_color);
        ~Checkbox();
        void draw(sf::RenderWindow *window) override;
        void update(sf::RenderWindow *window) override;
        const bool getState();
        const bool getHover();
};


#endif