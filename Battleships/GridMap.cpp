#include "stdafx.h"
#include "GridMap.h"

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
        if(!AreSurroundingTilesEmpty(ship.startPosition, ship.length+2,offset))
            return false;
        InsertShip(ship.startPosition,ship.length,offset);
        ships_.push_back(ship);
        return true;
    }

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
        const int directionOffset2 = directionOffset == 10 ? 1 : 10;
        const int startPositionOffset = -11;
        int skipValidatingColumn = -1;
        bool validateTile = true;
        if(startIndex % 10 == 0){
            skipValidatingColumn = 9;
            validateTile = false;
        }
        else if(startIndex % 9 == 0){
            skipValidatingColumn = 10;
            validateTile = false;
        }
        startIndex += startPositionOffset;
        for (int i = 0; i < length; i++){
            int searchIndex = startIndex;
                for (int j = startIndex; j <= startIndex+2; j++){
                    if(validateTile && searchIndex % skipValidatingColumn != 0){
                        if(searchIndex >= 0 && searchIndex < 100 && gridArray[searchIndex] != ' '){
                            
                            cout << "Captain your coordinates are too close to another ship! Try again!" << endl;
                            return false;
                        }
                    }
                    searchIndex += directionOffset2;
                }
            startIndex += directionOffset;
            skipValidatingColumn += directionOffset;
        }
        return true;
    }

    void GridMap::InsertShip(int startIndex, const int length, const int directionOffset){
        for(int i = 0; i < length; i++){
            SetTile(startIndex, 'S');
            startIndex += directionOffset;
        }
    }
