#include <SFML/Graphics.hpp>
#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile{

public:

    bool isPassable; //si vrai, le joueur peut se déplacer sur la case
    bool isExit; //si vrai, fin du jeu

    sf::Vector2f pos; //position 
    sf::Texture texture; 
    sf::Sprite sprite;
    
    GameTile(std::string,float,float,bool,bool);
    bool setUpSprite(std::string); //charge la texture et la met dans le sprite (à mettre à jour au fur&mesure)


};

#endif