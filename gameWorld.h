#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H



class GameWorld{

    sf::Vector2i exitPos; //position de la sortie //nous on a pas besoin de sortie ?
    sf::Vector2i playerPos; //position du joueur
    std::vector<sf::Vector2i> countryPositions; //positions des ennemis
    void setUpInitialState(); //initialise les positions du joueur, des ennemis et de la sortie
    void setUpCountryPositions(); //initialise les positions des ennemis
    void setUpTiles();//initialise les cases



public:
    std::vector< std::vector<GameTile *> > tiles; //matrice de pointeurs vers les cases
    int gridLength; //longueur de la grille
    GameWorld(); //constructeur

};

#endif