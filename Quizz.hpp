#pragma once
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Quizz
{
private:
    
    //Private Functions
    void initVariables();

public:
    //Variables
    bool isOpen;
    //type de quizz
    //questions + réponses

    //Functions
    

    //Constructors
    Quizz();
    virtual ~Quizz();

};