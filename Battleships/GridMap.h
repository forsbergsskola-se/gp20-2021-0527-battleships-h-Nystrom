#pragma once
#include "stdafx.h"
#include "Ship.h"

class GridMap{
    vector<Ship> ships_;
    char gridArray[100];

    public:
        GridMap();
        bool TryPlaceShip(Ship ship);
        void DisplayGrid();
        char Attack(int gridIndex);
        bool IsDefeated();
        void SetTile(int gridIndex, char marker);
        bool ShipBoundariesCheck(Ship ship);
    private:
        bool AreTilesEqualToChar(Ship ship,char character);
        void InsertShip(int startIndex, int length, int directionOffset);   
};
