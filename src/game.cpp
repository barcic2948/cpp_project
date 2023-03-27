#include "game.h"

Game::Game(int x, int y, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(x, y), title);
    
    window->setFramerateLimit(60);

    window->clear();
    window->display();

    std::cout << "Created widnow!" << std::endl;
}

Game::~Game() {
    delete this->window;
    std::cout << "Removed window!" << std::endl;
}

void Game::run() {
    while (window->isOpen()){
        sf::Event e;
        while (window->pollEvent(e)){
            if (e.type == sf::Event::Closed) {
                window->close();
                std::cout << "window closed" << std::endl;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                window->clear();
                std::cout<<"Q pressed!"<<std::endl;
            }
        }
    }
}