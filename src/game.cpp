#include "game.h"

Game::Game(int x, int y, std::string title) {

    WINDOW_HEIGHT = y;
    WINDOW_WIDTH = x;

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

void Game::mainMenu() {

    Custom_Text game_title("ASTEROIDS", 70, this->WINDOW_WIDTH / 2, (1.0/4.0) * this->WINDOW_HEIGHT, sf::Color::White);
    game_title.align_center();

    Custom_Text opt1("Option 1", 50, this->WINDOW_WIDTH/2, this->WINDOW_HEIGHT/2, sf::Color::White);
    opt1.align_center();
    Custom_Text opt2("Option 2", 50, this->WINDOW_WIDTH/2, this->WINDOW_HEIGHT/2 + 60, sf::Color::White);
    opt2.align_center();
    Custom_Text opt3("Option 3", 50, this->WINDOW_WIDTH/2, this->WINDOW_HEIGHT/2 + 120, sf::Color::White);
    opt3.align_center();

    Custom_Text author("Created by Bartek Cichy", 30, this->WINDOW_WIDTH, this->WINDOW_HEIGHT-30, sf::Color::White);
    author.align_right();
    author.set_underline(true);

    int menuIndex = 0;

    window->setFramerateLimit(60);

    while (window->isOpen()){
        sf::Event e;
        while (window->pollEvent(e)){
            if (e.type == sf::Event::Closed) {
                window->close();
                std::cout << "window closed" << std::endl;
            }
            if (e.type == sf::Event::KeyReleased) {
                switch (e.key.code) {
                    case sf::Keyboard::Down:
                        menuIndex = menuIndex < 2 ? menuIndex + 1 : menuIndex;
                        break;
                    case sf::Keyboard::Up:
                        menuIndex = menuIndex > 0 ? menuIndex - 1 : menuIndex;
                        break;
                    case sf::Keyboard::Q:
                        std::cout<<"Q pressed! index => "<< menuIndex <<std::endl;
                        break;
                }
            }
        }
        window->clear();

        switch(menuIndex) {
            case 0:
                opt1.set_underline(true);
                opt2.set_underline(false);
                opt3.set_underline(false);
                break;
            case 1:
                opt2.set_underline(true);
                opt1.set_underline(false);
                opt3.set_underline(false);
                break;
            case 2:
                opt3.set_underline(true);
                opt2.set_underline(false);
                opt1.set_underline(false);
                break;
        }
        
        game_title.draw(window);
        opt1.draw(window);
        opt2.draw(window);
        opt3.draw(window);
        author.draw(window);

        window->display();
    }
}