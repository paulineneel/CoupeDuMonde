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
    this->initQuestion();
    this->initAnswer();
    this->initBlock();
}

YesNoQuestion::~YesNoQuestion()
{

}

//Functions

void YesNoQuestion::initVariables()
{
    this->quizzType = "YesNo Question";
    this->isOpen = false;
    this->quizzCleared = false;
}

void YesNoQuestion::initQuestion()
{
    this->textFont.loadFromFile("Fonts/07558_CenturyGothic.ttf");
    this->textQuestion.setFont(this->textFont);
    this->textQuestion.setString(L"Test question.");
    this->textQuestion.setCharacterSize(24);
    this->textQuestion.setFillColor(sf::Color::Red);
    //this->textQuestion.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->textQuestion.setPosition(sf::Vector2f(300.f,100.f));
}

void YesNoQuestion::initAnswer()
{

}

void YesNoQuestion::initBlock()
{
    this->questionBox.setSize(sf::Vector2f(300.f,100.f));
    this->questionBox.setFillColor(sf::Color::White);
    this->questionBox.setPosition(sf::Vector2f(250.f,10.f));

    this->answerBox.setSize(sf::Vector2f(200.f,100.f));
    this->answerBox.setFillColor(sf::Color::White);
    this->answerBox.setPosition(sf::Vector2f(200.f,400.f));
}