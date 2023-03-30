#include "game.h"

Game::Game() {}

Game::~Game() {
    delete this->window;
    std::cout << "Removed window!" << std::endl;
}

bool Game::init() {
    std::cout << "Importing fonts: ";
    if (!this->font.loadFromFile(this->font_path)) {return false;}
    else { std::cout<<"Read font from file."<<std::endl;}

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ASTEROIDS");
    window->setFramerateLimit(60);
    std::cout << "Created widnow!" << std::endl;
    return true;
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

void Game::mainMenu() {
    
    Custom_Text text2(10, 10, 20, "TSOKURWAAAAAA", sf::Color::White, font);
    Custom_Button button(100, 100, 500, 100, font, "123", sf::Color::White, 30, this->color_button, this->color_button_on);

    while (window->isOpen()){
        sf::Vector2i position = sf::Mouse::getPosition(*window);
        sf::Event e;
        while (window->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window->close();
                std::cout << "window closed" << std::endl;
            }
            //if (e.type == sf::Event::KeyReleased) {
            //    switch (e.key.code) {
            //        case sf::Keyboard::Down:
            //            break;
            //        case sf::Keyboard::Up:
            //            break;
            //        case sf::Keyboard::Q:
            //            break;
            //    }
            //}
        }


        window->clear(this->color_background);
        text2.draw(window);
        button.update(position);
        button.draw(window);
        
        window->display();
    }
    
}