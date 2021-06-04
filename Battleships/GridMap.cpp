#include "GridMap.h"
#include <iostream>

    GridMap::GridMap(){
        gridArray[100];
        std::fill_n(gridArray, 100, ' ');
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
    bool GridMap::IsDefeated(){
        for(int i = 0; i < ships_.size(); i++){
            const char destroyedMarker = 'X';
            if(AreTilesEqualToChar(ships_[i], destroyedMarker)){
                std::cout << ships_[i].name << " has been destroyed!" << std::endl;
                ships_.erase(ships_.begin()+i);
            }
        }
        return ships_.size() == 0;
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
        const int startPositionOffset = -11;
        const int offset = ship.isVertical ? 10 : 1;

        
        if(!AreTilesEqualToChar(ship, ' ')){
            std::cout << "Captain the coordinates are out of bounds or occupied by another ship! Try again!" << std::endl;
            return false;
        }
        if(!AreSurroundingTilesEmpty(ship.startPosition+startPositionOffset, ship.length+2,offset))
            return false;
        InsertShip(ship.startPosition,ship.length,offset);
        ships_.push_back(ship);
        return true;
    }

    //TODO: Refactor duplications (if I have time)!
    bool GridMap::AreTilesEqualToChar(Ship ship, const char character){//AreTilesCharacter
        const int directionOffset = ship.isVertical ? 10 : 1;
        for(int i = 0; i < ship.length; i++){
            if(ship.startPosition < 0 || ship.startPosition >= 100 || gridArray[ship.startPosition] != character)
                return false;
            ship.startPosition += directionOffset;
        }
        return true;
    }

    bool GridMap::AreSurroundingTilesEmpty(int startIndex, const int length, const int directionOffset){
        const int directionOffset2 = directionOffset == 10 ? 0 : 10;
        for (int i = 0; i < length; i++){
            int searchIndex = startIndex;
                for (int j = startIndex; j < startIndex+3; j++){
                    if(searchIndex >= 0 && searchIndex < 100 && gridArray[searchIndex] != ' '){
                        std::cout << "Captain your coordinates are too close to another ship! Try again!" << std::endl;
                        return false;
                    }
                    searchIndex += directionOffset2;
                }
            startIndex += directionOffset;
        }
        return true;
    }
    void GridMap::InsertShip(int startIndex, const int length, const int directionOffset){
        for(int i = 0; i < length; i++){
            SetTile(startIndex, 'S');
            startIndex += directionOffset;
        }
    }
