#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Component {
    public:
        virtual ~Component() {};
        virtual void draw(sf::RenderWindow *window) = 0;
        virtual void update(sf::RenderWindow *window) = 0;
};

#endif