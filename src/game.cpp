#include "game.h"

Game::Game() {}

Game::~Game() {
    for(auto it : game_elements) { delete it; }
    std::cout << "Game entities removed" << std::endl;

    delete this->gate_color;
    delete this->text_color;
    delete this->hover_color;
    delete this->window;

    std::cout << "Removed window and colors" << std::endl;
}

bool Game::init() {
    std::cout << "Importing fonts: ";
    if (!this->font.loadFromFile(this->font_path)) {return false;}
    else { std::cout<<"Read font from file."<<std::endl;}

    window = new sf::RenderWindow(sf::VideoMode(this->window_width, this->window_height), "ASTEROIDS");
    window->setFramerateLimit(60);
    std::cout << "Created widnow!" << std::endl;
    return true;
}

void Game::run() {
    this->main_menu();
}

void Game::clear() {
    std::cout << "Clearing vector: ";
    for (auto it : this->game_elements) {
        delete it;
    }
    this->game_elements.clear();
    std::cout << "Removed all elements" << std::endl;
}

void Game::main_menu() {

    this->clear();

    Custom_Text *title = new Custom_Text(20, 20, "Hello World", this->font, 60, this->text_color);
    Button *game_start = new Button(20, 100, 330, 40, "Main menu", this->font, 30, this->gate_color, this->text_color, this->hover_color);
    Button *options = new Button(20, 150, 330, 40, "Options", this->font, 30, this->gate_color, this->text_color, this->hover_color);
    Button *quit = new Button(20, 200, 330, 40, "Quit", this->font, 30, this->gate_color, this->text_color, this->hover_color);

    this->game_elements.push_back(title);
    this->game_elements.push_back(game_start);
    this->game_elements.push_back(options);
    this->game_elements.push_back(quit);

    while (this->window->isOpen()){
        sf::Event e;
        while (this->window->pollEvent(e)){
            if (e.type == sf::Event::Closed) {
                this->window->close();
                std::cout << "window closed" << std::endl;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                this->window->clear();
                std::cout<<"Q pressed!"<<std::endl;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "Mouse pressed" << std::endl;
                if(game_start->getHover()) {
                    std::cout << "Start game" << std::endl;
                }
                else if (options->getHover()){
                    std::cout << "Options" << std::endl;
                    this->options();
                }
                else if (quit->getHover()) {
                    this->window->close();
                }
            }

            for(auto it : game_elements) {
                it->update(this->window);
            }
            this->window->clear();
            for(auto it : game_elements) {it->draw(this->window);}
            this->window->display();
        }
    }
}

void Game::options() {

    this->clear();

    Custom_Text *title = new Custom_Text(20, 20, "CHUJ World", this->font, 60, this->text_color);
    Button *game_start = new Button(20, 100, 330, 40, "Main menu", this->font, 30, this->gate_color, this->text_color, this->hover_color);
    Button *options = new Button(20, 150, 330, 40, "Options", this->font, 30, this->gate_color, this->text_color, this->hover_color);
    Button *quit = new Button(20, 200, 330, 40, "Quit", this->font, 30, this->gate_color, this->text_color, this->hover_color);

    this->game_elements.push_back(title);
    this->game_elements.push_back(game_start);
    this->game_elements.push_back(options);
    this->game_elements.push_back(quit);

    while (this->window->isOpen()){
        sf::Event e;
        while (this->window->pollEvent(e)){
            if (e.type == sf::Event::Closed) {
                this->window->close();
                std::cout << "window closed" << std::endl;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                this->window->clear();
                std::cout<<"Q pressed!"<<std::endl;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "Mouse pressed" << std::endl;
                if(game_start->getHover()) {
                    std::cout << "Start game" << std::endl;
                }
                else if (options->getHover()){
                    std::cout << "Options" << std::endl;
                }
                else if (quit->getHover()) {
                    this->window->close();
                }
            }

            for(auto it : game_elements) {
                it->update(this->window);
            }
            this->window->clear();
            for(auto it : game_elements) {it->draw(this->window);}
            this->window->display();
        }
    }
}