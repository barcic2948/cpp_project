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

    Custom_Text option1("Option 1", 50, this->WINDOW_WIDTH/2, this->WINDOW_HEIGHT/2, sf::Color::White);
    option1.align_center();
    Custom_Text option2("Option 2", 50, this->WINDOW_WIDTH/2, this->WINDOW_HEIGHT/2 + 60, sf::Color::White);
    option2.align_center();
    Custom_Text option3("Option 3", 50, this->WINDOW_WIDTH/2, this->WINDOW_HEIGHT/2 + 120, sf::Color::White);
    option3.align_center();

    Custom_Text author("Created by Bartek Cichy", 30, this->WINDOW_WIDTH, this->WINDOW_HEIGHT-30, sf::Color::White);
    author.align_right();

    

    std::vector<Custom_Text> todraw{game_title, option1, option2, option3, author};

    while (window->isOpen()){
        sf::Event e;
        while (window->pollEvent(e)){
            if (e.type == sf::Event::Closed) {
                window->close();
                std::cout << "window closed" << std::endl;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                std::cout<<"Q pressed!"<<std::endl;
            }
        }
        
        for(Custom_Text it : todraw) {
            it.draw(window);
        }

        window->display();
    }
}