#include "Game.h"

//Constuctors, Destructors
Game::Game()
{
   this->initVariables();
   this->initWindow(); 
   this->initCountries();
   this->initQuizz();
}

Game::~Game()
{
    delete this->window;
}


//Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    this->mapTexture.loadFromFile("worldmap.png");
    this->mapSprite.setTexture(this->mapTexture);
    this->mapSprite.scale(1.5,1.5); //change image scale (multiply it)

    //Game logic
    this->points = 0;
    this->quizz;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode,"Coupes du Monde",sf::Style::Titlebar | sf::Style::Close);
}

void Game::initCountries()
{
    this->country.setSize(sf::Vector2f(266.f,300.f)); //relative window size
    this->country.setFillColor(sf::Color::Cyan);

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            this->country.setPosition(sf::Vector2f(0.f + j*266.f,0.f +i*300.f));
            this->countries.push_back(this->country);
        }
    }

    this->countries[1].setFillColor(sf::Color::Red);
    this->countries[2].setFillColor(sf::Color::Black);
    this->countries[3].setFillColor(sf::Color::Blue);
    this->countries[4].setFillColor(sf::Color::Yellow);
}

void Game::initQuizz()
{
    for(int i =0; i<6;i++)
    {
        this->allQuizz.push_back(this->quizz);
    }

    this->isOneQuizzOpen = false;
}

//Functions

int Game::whichQuizzOpen()
{
    int ind = -1;
    for (int i=0; i<allQuizz.size(); i ++)
    {
        if(allQuizz[i].isOpen)
        {
            ind = i;
        }
    }

    return ind;
}

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

void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateCountries()
{
    //update countries colors
    for(int i=0; i<this->countries.size(); i++)
    {
        if(this->allQuizz[i].quizzCleared) 
        {
            
            this->countries[i].setFillColor(sf::Color::Green);
            
        }
    }
}

void Game::updateQuizz()
{
    for(int i=0; i<this->countries.size(); i++)
    {
        if(!this->isOneQuizzOpen)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                if (this->countries[i].getGlobalBounds().contains(this->mousePosView))
                {
                    this->allQuizz[i].openQuizz();
                }
            }
        }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int ind = this->whichQuizzOpen();
        //std::cout << "Quizz open :" << ind << "\n" << std::endl;
        if (this->allQuizz[ind].answerBox.getGlobalBounds().contains(this->mousePosView))
            {
                this->allQuizz[ind].closeQuizz();
                this->isOneQuizzOpen = false;
            }
    }

}

void Game::update()
{
    this->pollEvents();

    this->updateMousePositions();

    this->updateCountries();

    this->updateQuizz();
}

void Game::renderCountries()
{
    for(auto &e : this->countries)
    {
        this->window->draw(e);
    }
}

void Game::renderQuizz(YesNoQuestion q)
{
    
    this->window->draw(q.questionBox);
    this->window->draw(q.answerBox);
    this->window->draw(q.textQuestion); 
}

void Game::render() //visualizing all the positions, points
{
    //First Game window
    this->window->clear();

    for(int i=0; i<6; i++)
    {
        if (this->allQuizz[i].isOpen)
        {
            this->renderQuizz(allQuizz[i]);
            this->isOneQuizzOpen = true;
        }
    }

    if(!this->isOneQuizzOpen)
    {
        //draw game objects
        this->window->draw(this->mapSprite);
        this->renderCountries();
    }
    

    this->window->display();
}


//Accessors

const bool Game::running() const
{
    return this->window->isOpen();
}

