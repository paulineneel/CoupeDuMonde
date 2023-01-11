#include "Quizz.hpp"

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
    this->questions.setString("Est-ce qu'il fait beau ?");
    this->questions.setCharacterSize(26);
    this->questions.setFillColor(sf::Color::Red);

    this->questionBox.setSize(sf::Vector2f(600.f,800.f));
    this->questionBox.setFillColor(sf::Color::White);
    this->questionBox.setPosition(sf::Vector2f(0.f,0.f));

    for(int i=0;i<2;i++)
    {
        if (i==0)
        {
            this->reponse.setString("Oui");
            this->reponse.setCharacterSize(26);
            this->reponse.setFillColor(sf::Color::Black);
            //this->answerBox.push_back(this->reponse);
        }
            
    }


    this->answerBox.setSize(sf::Vector2f(100.f,100.f));
    this->answerBox.setFillColor(sf::Color::White);
    this->answerBox.setPosition(sf::Vector2f(400.f,300.f));


}