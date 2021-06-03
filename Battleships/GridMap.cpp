#include "GridMap.h"
#include <iostream>

GridMap::GridMap(){
    gridArray[100];
    std::fill_n(gridArray, 100, ' ');
}
//TODO: Refactor!
bool GridMap::TryPlaceShip(const Ship ship){
    //Check for out of bounds or other ships.
    const int offset = ship.isVertical ? 10 : 1;    
    int gridIndex = ship.startPosition;
    for(int i = 0; i < ship.length; i++){
        if(gridIndex < 0 || gridIndex >= 100 && !IsEmpty(gridIndex))
            return false;
        gridIndex += offset;
    }
    //Check for adjacent ships
    const int startPositionOffset = -11;
    const int offset2 = ship.isVertical ? 0 : 10;
    gridIndex = ship.startPosition + startPositionOffset;
    for (int i = 0; i < ship.length+2; i++){
        int temp = gridIndex;
        for (int j = gridIndex; j < gridIndex+3; j++){
            if(temp >= 0 && temp < 100 && !IsEmpty(temp))//TODO:Fix
                return false;
            temp += offset2;
        }
        gridIndex += offset;
    }
    //Adding the ship to the grid...
    gridIndex = ship.startPosition;
    for(int i = 0; i < ship.length; i++){
        SetTile(gridIndex, 'S');
        gridIndex += offset;
    }
    return true;
}

bool GridMap::IsEmpty(const int gridIndex){
    return gridArray[gridIndex] == ' ';
}
char GridMap::GetTileInfo(const int gridIndex){
    return gridArray[gridIndex];
}
void GridMap::SetTile(const int gridIndex, const char marker){
    if(gridIndex < 100 && gridIndex >= 0)
        gridArray[gridIndex] = marker;
}
void GridMap::DisplayGrid(){
    char leftColumn[]{'0', '1', '2', '3', '4', '5', '6', '7', '8','9'};
    int currIndex = 0;
    DisplayTopRow();
    for (int i = 0; i < 10; i++){  
        for (int j = 0; j <= 10;j++){
            const char temp = j == 0 ? leftColumn[i] : gridArray[currIndex++];
            std::cout << '[' << temp << ']';
        }
        std::cout << "" <<std::endl;
    }
}
void GridMap::DisplayTopRow(){
    char topRow[]{'*', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','J', 'K'};
    for (int i = 0; i <= 10; i++){
        std::cout << '[' << topRow[i] << ']';
    }
    std::cout << "" << std::endl;
}