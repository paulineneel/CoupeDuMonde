#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <SFML/OpenGL.hpp>
#include "gameWorld.cpp"
#include "gameTile.cpp"


int main(){
    //variables
    float windowWidth = 800;
    float windowHeight = 800;

    // Créez une fenêtre SFML + son titre
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Carte du monde");
    

    GameWorld gameWorld = GameWorld();


    // // Charger l'image de la carte du monde en tant que texture
    // sf::Texture mapTexture;
    // if (!mapTexture.loadFromFile("/home/portable014/Bureau/neelp_1/MAIN_4_PC/INfo/CoupeDuMonde/photos/world_map1.png")) 
    // {
    //     std::cout << "Erreur : impossible de charger l'image de la carte du monde" << std::endl;
    //     return(1);
    // }

    // // Créez un sprite pour afficher la carte
    // sf::Sprite mapSprite;
    // mapSprite.setTexture(mapTexture);
    // mapSprite.setPosition(sf::Vector2f(50,50)); // Positionner la map en haut à gauche de la fenêtre
    // mapSprite.setScale(sf::Vector2f(0.5,0.5)); // Réduire la taille de la carte de 50%



    // Boucle principale de jeu
    while (window.isOpen()) {


        // Traitez les événements
        sf::Event event;
        while (window.pollEvent(event)) { //on vérifie s'il y a des événements à traiter

            if (event.type == sf::Event::Closed) {
                window.close();
            // }else if(event.type == sf::Event::MouseButtonPressed){
            //     std::cout << "Mouse button pressed" << std::endl;           

            // }else if(event.type == sf::Event::KeyPressed){
            //     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            //         mapSprite.move(-5.f, 0.f);
            //     }
            
            }

        }

        // Effacer l'écran
        window.clear();

        for(int i =0 ; i<gameWorld.gridLength;i++){
            for(int j =0 ; j<gameWorld.gridLength;j++){
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        
        }


        //Afficher l'écran
        window.display();
        //mapSprite.move(5.f, 5.f);
    }
}