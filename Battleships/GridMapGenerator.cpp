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
            ship.name = shipNames[i];
            
            while (true){
                std::cout << "Ship: " << ship.name << " Size: " << ship.length << std::endl;
                ship.isVertical = InputHandler().SimpleRequest('v', 'h', "Rotation: V: Vertical, H: Horizontal");
                ship.startPosition = InputHandler().CoordinateToIndex(0,9, "Position: Enter coordinates between A0 to J9");
                if(gridMap.TryPlaceShip(ship))
                    break;
                
            }
        }
        return gridMap;
    }


