#include "GridMapGenerator.h"
#include "Ship.h"
#include <iostream>

#include "InputHandler.h"

GridMap GridMapGenerator::GetEmpty(){
        return GridMap();
    }
    GridMap GridMapGenerator::SetBattleShips(){
        int shipLenght[5]{5,4,3,2,2};;
        std::string shipNames[5]{"Carrier", "Battleship", "Destroyer", "SubMarine", "Patrol boat"};
        auto gridMap = GridMap();
        auto ship = Ship();
        
        for(int i = 0; i < 5; i++){
            std::cout << std::endl;
            gridMap.DisplayGrid();
            ship.length = shipLenght[i];
            std::string shipName = shipNames[i];
            
            do{
                std::cout << "Ship: " << shipName << " Size: " << ship.length << std::endl;
                ship.isVertical = SetShipRotation();
                ship.startPosition = SetShipPosition();
            }
            while (!gridMap.TryPlaceShip(ship));
        }
        return gridMap;
    }
    bool GridMapGenerator::SetShipRotation(){
            return InputHandler().SimpleRequest('v', 'h', "Rotation: V: Vertical, H: Horizontal");
    }
    int GridMapGenerator::SetShipPosition(){
        while (true){
            //TODO: Input handler
            //TODO: Coordinates to int handler
            return -1;
        }
    }


