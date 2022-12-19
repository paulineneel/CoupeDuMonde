#include "gameWorld.h"

GameWorld::GameWorld(){
    gridLength = 8;
    setUpInitialState();
}

void GameWorld::setUpInitialState(){
    exitPos = sf::Vector2i(1,0);
    playerPos = sf::Vector2i(gridLength-1,gridLength-1);
    setUpEnemyPositions();
    setUpTiles();
}

void GameWorld::setUpEnemyPositions(){
    enemyPositions.clear();
    enemyPositions.push_back(sf::Vector2i(0,2));
    enemyPositions.push_back(sf::Vector2i(6,0));
    enemyPositions.push_back(sf::Vector2i(2,7));
}   

void GameWorld::setUpTiles(){
    tiles.clear();

    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile("photos/sea.png", 0,0,false,false));
    firstRow.push_back(new GameTile("photos/sea.png", 50,0,true,true));
    firstRow.push_back(new GameTile("photos/sea.png", 100,0,false,false));
    firstRow.push_back(new GameTile("photos/sea.png", 150,0,false,false));
    firstRow.push_back(new GameTile("photos/sea.png", 200,0,false,false));
    firstRow.push_back(new GameTile("photos/sea.png", 250,0,false,false));
    firstRow.push_back(new GameTile("photos/sea.png", 300,0,true,false));
    firstRow.push_back(new GameTile("photos/sea.png", 350,0,false,false));
    tiles.push_back(firstRow);

    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile("photos/sea.png", 0,50,false,false));
    secondRow.push_back(new GameTile("photos/canada.png", 50,50,true,true));
    secondRow.push_back(new GameTile("photos/blue.png", 100,50,true,false));
    secondRow.push_back(new GameTile("photos/blue.png", 150,50,true,false));
    secondRow.push_back(new GameTile("photos/blue.png", 200,50,true,false));
    secondRow.push_back(new GameTile("photos/green.png", 250,50,false,false));
    secondRow.push_back(new GameTile("photos/blue.png", 300,50,true,false));
    secondRow.push_back(new GameTile("photos/sea.png", 350,50,false,false));
    tiles.push_back(secondRow);

    std::vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile("photos/sea.png", 0,100,false,false));
    thirdRow.push_back(new GameTile("photos/blue.png", 50,100,true,true));
    thirdRow.push_back(new GameTile("photos/red.png", 100,100,true,false));
    thirdRow.push_back(new GameTile("photos/blue.png", 150,100,true,false));
    thirdRow.push_back(new GameTile("photos/blue.png", 200,100,true,false));
    thirdRow.push_back(new GameTile("photos/green.png", 250,100,false,false));
    thirdRow.push_back(new GameTile("photos/blue.png", 300,100,true,false));
    thirdRow.push_back(new GameTile("photos/sea.png", 350,100,false,false));
    tiles.push_back(thirdRow);

    std::vector<GameTile *> fourthRow;
    fourthRow.push_back(new GameTile("photos/sea.png", 0,150,false,false));
    fourthRow.push_back(new GameTile("photos/blue.png", 50,150,true,true));
    fourthRow.push_back(new GameTile("photos/blue.png", 100,150,true,false));
    fourthRow.push_back(new GameTile("photos/red.png", 150,150,true,false));
    fourthRow.push_back(new GameTile("photos/blue.png", 200,150,true,false));
    fourthRow.push_back(new GameTile("photos/green.png", 250,150,false,false));
    fourthRow.push_back(new GameTile("photos/blue.png", 300,150,true,false));
    fourthRow.push_back(new GameTile("photos/sea.png", 350,150,false,false));
    tiles.push_back(fourthRow);

    std::vector<GameTile *> fifthRow;
    fifthRow.push_back(new GameTile("photos/sea.png", 0,200,false,false));
    fifthRow.push_back(new GameTile("photos/blue.png", 50,200,true,true));
    fifthRow.push_back(new GameTile("photos/blue.png", 100,200,true,false));
    fifthRow.push_back(new GameTile("photos/blue.png", 150,200,true,false));
    fifthRow.push_back(new GameTile("photos/blue.png", 200,200,true,false));
    fifthRow.push_back(new GameTile("photos/green.png", 250,200,false,false));
    fifthRow.push_back(new GameTile("photos/blue.png", 300,200,true,false));
    fifthRow.push_back(new GameTile("photos/sea.png", 350,200,false,false));
    tiles.push_back(fifthRow);

    std::vector<GameTile *> sixthRow;
    sixthRow.push_back(new GameTile("photos/sea.png", 0,250,false,false));
    sixthRow.push_back(new GameTile("photos/blue.png", 50,250,true,true));
    sixthRow.push_back(new GameTile("photos/red.png", 100,250,true,false));
    sixthRow.push_back(new GameTile("photos/blue.png", 150,250,true,false));
    sixthRow.push_back(new GameTile("photos/blue.png", 200,250,true,false));
    sixthRow.push_back(new GameTile("photos/green.png", 250,250,false,false));
    sixthRow.push_back(new GameTile("photos/blue.png", 300,250,true,false));
    sixthRow.push_back(new GameTile("photos/sea.png", 350,250,false,false));
    tiles.push_back(sixthRow);
    
    std::vector<GameTile *> seventhRow;
    seventhRow.push_back(new GameTile("photos/sea.png", 0,300,false,false));
    seventhRow.push_back(new GameTile("photos/blue.png", 50,300,true,true));
    seventhRow.push_back(new GameTile("photos/blue.png", 100,300,true,false));
    seventhRow.push_back(new GameTile("photos/blue.png", 150,300,true,false));
    seventhRow.push_back(new GameTile("photos/red.png", 200,300,true,false));
    seventhRow.push_back(new GameTile("photos/green.png", 250,300,false,false));
    seventhRow.push_back(new GameTile("photos/blue.png", 300,300,true,false));
    seventhRow.push_back(new GameTile("photos/sea.png", 350,300,false,false));
    tiles.push_back(seventhRow);

    std::vector<GameTile *> eighthRow;
    eighthRow.push_back(new GameTile("photos/sea.png", 0,350,false,false));
    eighthRow.push_back(new GameTile("photos/sea.png", 50,350,true,true));
    eighthRow.push_back(new GameTile("photos/sea.png", 100,350,true,false));
    eighthRow.push_back(new GameTile("photos/sea.png", 150,350,true,false));
    eighthRow.push_back(new GameTile("photos/sea.png", 200,350,true,false));
    eighthRow.push_back(new GameTile("photos/sea.png", 250,350,false,false));
    eighthRow.push_back(new GameTile("photos/sea.png", 300,350,true,false));
    eighthRow.push_back(new GameTile("photos/sea.png", 350,350,false,false));
    tiles.push_back(eighthRow);


}