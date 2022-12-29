#include "Game.h"

//Private Functions

void Game::initVariables()
{
    this->window = nullptr;
    this->mapTexture.loadFromFile("worldmap.png");
    this->mapSprite.setTexture(this->mapTexture);
    this->mapSprite.scale(1.5,1.5); //change image scale (multiply it)
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

            case sf::Event::MouseButtonPressed:
                //Create quizz //update window
                this->quizz.isOpen = 1;
                while(this->quizz.isOpen==1)
                {
                    this->startQuizz();
                    switch (this->event.type) //pb boucle infini (event bloqué sur mousebuttonpressed?)
                    {
                        case sf::Event::Closed:
                            std::cout<<"Close"<<std::endl;
                            this->quizz.isOpen = 0;
                            this->render();
                            break;
                        case sf::Event::KeyPressed:
                            if (this->event.key.code == sf::Keyboard::Escape)
                                this->quizz.isOpen = 0;
                                this->render();
                            break;
                    }
                    
                }
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

void Game::startQuizz()
{
    this->window->clear(sf::Color::White);

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