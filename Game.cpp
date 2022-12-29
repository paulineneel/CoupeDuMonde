#include "Game.h"

//Private Functions

void Game::initVariables()
{
    this->window = nullptr;
    this->mapTexture.loadFromFile("worldmap.png");
    this->mapSprite.setTexture(this->mapTexture);
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode,"Carte du monde",sf::Style::Titlebar | sf::Style::Close);
}

//Functions

void Game::pollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render() //visualizing all the positions, points
{
    this->window->clear();

    //draw game objects
    this->window->draw(this->mapSprite);

    this->window->display();
}

//Accessors

const bool Game::running() const
{
    return this->window->isOpen();
}


//Constuctors, Destructors
Game::Game()
{
   this->initVariables();
   this->initWindow(); 
}

Game::~Game()
{
    delete this->window;
}