#pragma once

#include "Quizz.h"

/* Game engine */

class Game
{
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    //Map
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    //Quizz
    Quizz quizz;

    //Private Functions
    void initVariables();
    void initWindow();


public:
    //Functions
    void pollEvents();
    void update();
    void render();
    void startQuizz();

    //Accessors
    const bool running() const;

    //Constructors
    Game();
    virtual ~Game();
};