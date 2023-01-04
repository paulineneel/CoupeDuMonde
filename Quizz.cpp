#include "Quizz.h"

//Constructors, Destructors
Quizz::Quizz()
{
    
}

Quizz::~Quizz()
{

}

void Quizz::openQuizz()
{
    this->isOpen = true;
}

void Quizz::closeQuizz()
{
    this->isOpen = false;
    this->quizzCleared = true;
}

//

//Constructors, Destructors
YesNoQuestion::YesNoQuestion()
{
    this->initVariables();
    this->initQuestionAnswer();
}

YesNoQuestion::~YesNoQuestion()
{

}

//Functions

void YesNoQuestion::initVariables()
{
    this->quizzType = "test";
    this->isOpen = false;
    this->quizzCleared = false;
}

void YesNoQuestion::initQuestionAnswer()
{
    this->questionBox.setSize(sf::Vector2f(100.f,300.f));
    this->questionBox.setFillColor(sf::Color::White);
    this->questionBox.setPosition(sf::Vector2f(250.f,10.f));

    this->answerBox.setSize(sf::Vector2f(100.f,100.f));
    this->answerBox.setFillColor(sf::Color::White);
    this->answerBox.setPosition(sf::Vector2f(400.f,300.f));
}