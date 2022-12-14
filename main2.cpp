#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <SFML/OpenGL.hpp>


int main(){

    // Créez une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(5000, 5000), "Carte du monde");

    // Charger l'image de la carte du monde en tant que texture
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("carte-du-monde.jpeg")) 
    {
        //std::count << "Erreur : impossible de charger l'image de la carte du monde" << std::endl;
        //return(1);
    }

    // Créez un sprite pour afficher la carte
    sf::Sprite mapSprite;
    mapSprite.setTexture(mapTexture);

    // Boucle principale de jeu
    while (window.isOpen()) {
        // Traitez les événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Effacer l'écran
        window.clear();

        // Dessinez la carte
        window.draw(mapSprite);

        //Afficher l'écran
        window.display();
    }
}
