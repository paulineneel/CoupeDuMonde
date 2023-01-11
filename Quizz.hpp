#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Quizz
{
public:
    //Variables
    std::string quizzType;
    bool isOpen;
    bool quizzCleared;
    

    sf::RectangleShape questionBox;

    //Functions
    virtual void initVariables() = 0;
    void openQuizz();
    void closeQuizz();

    //Constructors
    //Quizz(std::string qType);
    Quizz();
    ~Quizz();
};

class YesNoQuestion: public Quizz
{
public:
    //Variables
    std::vector<sf::RectangleShape> answers;
    sf::RectangleShape answerBox;
    sf::Text questions;
    sf::Text reponse;

    //Functions
    void initVariables();
    void initQuestionAnswer();


    //YesNoQuestion(std::string qType);
    YesNoQuestion();
    ~YesNoQuestion();
};