#include <iostream>
#include <stdio.h>
#include "Game.h"

int main()
{
    // Init Game Engine
    Game game;

    // Game loop
    while (game.running()) 
    {
        //Update
        game.update();

        //Visualization
        game.render();
        
    }
    return 0;
}
    
