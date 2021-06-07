#include "stdafx.h"
#include "GridMap.h"
#include "Vector2.h"

GridMap::GridMap(){
        gridArray[100];
        fill_n(gridArray, 100, ' ');
    }

    char GridMap::Attack(const int gridIndex){
        const char hitMarker = gridArray[gridIndex];
        switch (hitMarker){
            case ' ':
                cout<< "Miss!" << endl;
                SetTile(gridIndex,'M');
                return 'M';
            case 'S':
                cout<< "Hit!" << endl;
                SetTile(gridIndex,'X');
                return 'X';
            case 'X':
                cout<< "Miss, old hit..!" << endl;
                return 'X';
            case 'M':
                cout<< "Miss, old miss..!" << endl;
            return 'M';
            default:
                cout << "Error!" << endl;
                return '?';
        }
    }

    bool GridMap::IsDefeated(){
        for(int i = 0; i < ships_.size(); i++){
            const char destroyedMarker = 'X';
            if(AreTilesEqualToChar(ships_[i], destroyedMarker)){
                cout << ships_[i].name << " has been destroyed!" << endl;
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
        cout << "[*][A][B][C][D][E][F][G][H][I][J]" << endl;
        for (int i = 0; i < 10; i++){  
            for (int j = 0; j <= 10;j++){
                const char temp = j == 0 ? leftColumn[i] : gridArray[currIndex++];
                cout << '[' << temp << ']';
            }
            cout << "" << endl;
        }
    }

    bool GridMap::TryPlaceShip(const Ship ship){
        const int offset = ship.isVertical ? 10 : 1;

        if(!AreTilesEqualToChar(ship, ' ')){
            cout << "Captain the coordinates are out of bounds or occupied by another ship! Try again!" << endl;
            return false;
        }
        if(!ShipBoundariesCheck(ship)){//TODO: this!
            cout << "Captain the coordinates are too close too another ship! Try again!" << endl;
            return false;
        }
        InsertShip(ship.startPosition,ship.length,offset);
        ships_.push_back(ship);
        return true;
    }

    bool GridMap::AreTilesEqualToChar(Ship ship, const char character){
        const int directionOffset = ship.isVertical ? 10 : 1;
        for(int i = 0; i < ship.length; i++){
            if(ship.startPosition < 0 || ship.startPosition >= 100 || gridArray[ship.startPosition] != character)
                return false;
            ship.startPosition += directionOffset;
        }
        return true;
    }

    bool GridMap::ShipBoundariesCheck(const Ship ship){
    
        int startIndex = ship.startPosition - 11;
        const int startOffsetX = ship.startPosition % 10 == 0 ? 1:0;
        const int endOffsetX = (ship.startPosition+1) % 10 == 0 ? 1:0;
        const Vector2 vector2 = ship.GetScale();
        
        for (int y = 0; y < vector2.y; y++){
            for(int x = startOffsetX; x < vector2.x-endOffsetX; x++){
                const int currentIndex = x+startIndex;
                if(currentIndex >= 0 && currentIndex < 100 && gridArray[currentIndex] != ' '){
                    return false;
                }
            }
            startIndex += 10;
        }
        return true;
    }

    void GridMap::InsertShip(int startIndex, const int length, const int directionOffset){
        for(int i = 0; i < length; i++){
            SetTile(startIndex, 'S');
            startIndex += directionOffset;
        }
    }
