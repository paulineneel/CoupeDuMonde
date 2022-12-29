#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

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

    //Private Functions
    void initVariables();
    void initWindow();


public:
    //Functions
    void pollEvents();
    void update();
    void render();

    //Accessors
    const bool running() const;

    //Constructors
    Game();
    virtual ~Game();
};