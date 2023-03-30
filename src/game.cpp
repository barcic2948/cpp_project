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
    
    Custom_Text title(WINDOW_WIDTH/2, 100, 80, "ASTEROIDS", sf::Color::White, font);
    title.center();
    Custom_Button game_start(WINDOW_WIDTH/2, 300, 410, 60, font, "Start the game", sf::Color::White, 30, this->color_button, this->color_button_on);
    game_start.center();
    Custom_Button options(WINDOW_WIDTH/2, 380, 410, 60, font, "Options", sf::Color::White, 30, this->color_button, this->color_button_on);
    options.center();
    Custom_Button quit(WINDOW_WIDTH/2, 460, 410, 60, font, "Quit", sf::Color::White, 30, this->color_button, this->color_button_on);\
    quit.center();
    
    while (window->isOpen()) {
        sf::Vector2i position = sf::Mouse::getPosition(*window);
        sf::Event e;
        while (window->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window->close();
                std::cout << "window closed" << std::endl;
            }
            if (game_start.update(position)) {
                if (e.type == sf::Event::MouseButtonReleased) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "WAT" << std::endl;
                    }
                }
            }
            if (options.update(position)) {
                if (e.type == sf::Event::MouseButtonReleased) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "WAT" << std::endl;
                    }
                }
            }
            if (quit.update(position)) {
                if (e.type == sf::Event::MouseButtonReleased) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        window->close();
                        std::cout << "window closed" << std::endl;
                    }
                }
            }
        }


        window->clear(this->color_background);
        title.draw(window);
        game_start.draw(window);
        options.draw(window);
        quit.draw(window);
        
        window->display();
    }
    
}