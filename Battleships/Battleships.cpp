#include <iostream>
#include "GridMap.h"


//TODO: Refactor!
GridMap GridMapShipSetUp(){
    auto gridMap = GridMap();
    const int shipLenght[]{5,4,3,2,2};
    auto ship = Ship();
    for(int i = 0; i < 5; i++){
            std::cout << std::endl;
            gridMap.DisplayGrid();
            ship.length = shipLenght[i];
        //Set rotation:
            ship.isVertical = true;//TODO: Remove temp!
            // std::cout << "Vertical or horizontal? v/h" << std::endl;
            // char input;
            // std::cin >> input;
            // ship.isVertical = input == 'v';
        //Set position:
            // std::cout << "Pick a coordinate between 0A and 9K" << std::endl;
            // int input2;
            // char input3;
            // std::cin >> input2 >> input3;
            gridMap.TryPlaceShip(ship);
            ship.startPosition += 2;
    }
    return gridMap;
}
int main(){
    auto gridMapPlayer1 = GridMapShipSetUp();
    gridMapPlayer1.DisplayGrid();
    return 0;
}
