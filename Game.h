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

    //Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Map
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    

    //Game logic
    int score;
    std::vector<YesNoQuestion> allQuizz;
    YesNoQuestion quizz;
    bool isOneQuizzOpen;

    //Countries
    std::vector<sf::RectangleShape> countries; 
    sf::RectangleShape country; //à changer en sprite pour mettre texture (dcp les fonctions de bases changent)
    

    //Private Functions
    void initVariables();
    void initWindow();
    void initCountries();
    void initQuizz();


public:

    //Functions
    void pollEvents();
    int whichQuizzOpen();
    void resetCountriesColors();

    void updateMousePositions();
    void updateCountries();
    void updateQuizz();
    void update();

    void renderCountries();
    void renderQuizz(YesNoQuestion q);
    void render();

    //Accessors
    const bool running() const;

    //Constructors
    Game();
    ~Game();
};