#pragma once
#include "stdafx.h"
#include "Ship.h"

class GridMap{
    vector<Ship> ships_;
    char gridArray[100];
    bool AreTilesEqualToChar(Ship ship,char character);
    void InsertShip(int startIndex, int length, int directionOffset);
public:
    GridMap();
    bool TryPlaceShip(Ship ship);
    void SetTile(int gridIndex, char marker);
    void DisplayGrid();
    char Attack(int gridIndex);
    bool IsDefeated();
};
