#pragma once

#include "component.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Component
{
    private:
        sf::Sprite *sprite;
        sf::Texture *texture;

        void initTexture();
        void initSprite();

    public:
        Player(/* args */);
        ~Player();
        void draw(sf::RenderWindow *window) override;
        void update(sf::RenderWindow *window) override;
};

#endif