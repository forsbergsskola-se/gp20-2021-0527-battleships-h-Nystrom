#include "GridMapGenerator.h"
#include "InputHandler.h"
#include "Ship.h"
#include <iostream>

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
            
            while (true){
                std::cout << "Ship: " << shipName << " Size: " << ship.length << std::endl;
                ship.isVertical = SetShipRotation();
                ship.startPosition = SetShipPosition();
                if(gridMap.TryPlaceShip(ship))
                    break;
                
            }
        }
        return gridMap;
    }
    bool GridMapGenerator::SetShipRotation(){
            return InputHandler().SimpleRequest('v', 'h', "Rotation: V: Vertical, H: Horizontal");
    }
    int GridMapGenerator::SetShipPosition(){
        while (true){
            return InputHandler().CoordinateToIndex(0,9, "Position: Enter coordinates between A0 to J9");
        }
    }


