#include "GridMap.h"
#include <iostream>

    GridMap::GridMap(){
        gridArray[100];
        std::fill_n(gridArray, 100, ' ');
    }

    bool GridMap::IsEmpty(const int gridIndex){
        return gridArray[gridIndex] == ' ';
    }
    char GridMap::Attack(const int gridIndex){
        const char hitMarker = gridArray[gridIndex];
        switch (hitMarker){
            case ' ':
                std::cout<< "Miss!" << std::endl;
                SetTile(gridIndex,'M');
                return 'M';
            case 'S':
                std::cout<< "Hit!" << std::endl;
                SetTile(gridIndex,'X');
                return 'X';
            case 'X':
                std::cout<< "Miss, old hit..!" << std::endl;
                return 'X';
            case 'M':
                std::cout<< "Miss, old miss..!" << std::endl;
            return 'M';
            default:
                std::cout << "Error!" << std::endl;
                return '?';
        }
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
        char topRow[]{'*', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J'};
        for (int i = 0; i <= 10; i++){
            std::cout << '[' << topRow[i] << ']';
        }
        std::cout << "" << std::endl;
    }

    bool GridMap::TryPlaceShip(const Ship ship){
        const int offset = ship.isVertical ? 10 : 1;
        const int startPositionOffset = -11;

        if(!AreTilesEmpty(ship.startPosition, ship.length, offset))
            return false;
        if(!AreSurroundingTilesEmpty(ship.startPosition+startPositionOffset, ship.length+2,offset))
            return false;
        return InsertShip(ship.startPosition,ship.length,offset);
    }

    //TODO: Refactor duplications (if I have time)!
    bool GridMap::AreTilesEmpty(int startIndex, const int length, const int directionOffset){
        for(int i = 0; i < length; i++){
            if(startIndex < 0 || startIndex >= 100 || !IsEmpty(startIndex)){
                std::cout << "Captain the coordinates are out of bounds or occupied by another ship! Try again!" << std::endl;
                return false;
            }
                
            startIndex += directionOffset;
        }
        return true;
    }

    bool GridMap::AreSurroundingTilesEmpty(int startIndex, const int length, const int directionOffset){
        const int directionOffset2 = directionOffset == 10 ? 0 : 10;
        for (int i = 0; i < length; i++){
            int temp = startIndex;
                for (int j = startIndex; j < startIndex+3; j++){
                    if(temp >= 0 && temp < 100 && !IsEmpty(temp)){
                        std::cout << "Captain your coordinates are too close to another ship! Try again!" << std::endl;
                        return false;
                    }
                        
                    temp += directionOffset2;
                }
            startIndex += directionOffset;
        }
        return true;
    }

    bool GridMap::InsertShip(int startIndex, const int length, const int directionOffset){
        for(int i = 0; i < length; i++){
            SetTile(startIndex, 'S');
            startIndex += directionOffset;
        }
        return true;
    }
