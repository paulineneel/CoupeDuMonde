#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <SFML/OpenGL.hpp>


int main()
{

    // Créez une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(600, 400), "Carte du monde");

    // Charger l'image de la carte du monde en tant que texture
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("worldmap.png")) 
    {
        std::cout << "Erreur : impossible de charger l'image de la carte du monde" << std::endl;
        return(1);
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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::RenderWindow window2(sf::VideoMode(200, 200), "Quiz 1");
                while (window2.isOpen()){
                    // Traitez les événements
                    sf::Event event;   
                    while (window2.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                window2.close();
                        }
                    }

                    window2.clear();
                    window2.draw(mapSprite);
                    window2.display();
                }
            }

        // Effacer l'écran
        window.clear();

        // Dessinez la carte
        window.draw(mapSprite);

        //Afficher l'écran
        window.display();
        }
    return 0;
    }
    
