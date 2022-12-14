#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <SFML/OpenGL.hpp>

class Avatar
{
    sf::Texture image;
    int longueurcheveux;

    void updateimage();

};

class Jeux 
{
    public:
    int vie;


    Jeux();
    void creerpartie();
    void finpartie();
    void getcolorclic();

};

class Pays 
{
    public :


};