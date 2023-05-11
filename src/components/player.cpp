#include "player.h"

Player::Player() {
    this->initTexture();
    this->initSprite();
}

Player::~Player() {
    delete this->sprite;
    delete this->texture;
}

void Player::initSprite() {
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->texture);
}

void Player::initTexture() {
    this->texture = new sf::Texture();
    if (this->texture->loadFromFile("textures/ship.png")) {

    }
    else {
        std::cerr << "Could not load texture" << std::endl;
    }
}


void Player::draw(sf::RenderWindow *window) {

}
void Player::update(sf::RenderWindow *window) {

}