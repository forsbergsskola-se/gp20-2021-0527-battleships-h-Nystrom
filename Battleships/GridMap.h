#pragma once
#include "Ship.h"

class GridMap{
    char gridArray[100];
    static void DisplayTopRow();
    bool AreTilesEmpty(int startIndex, int length, int directionOffset);
    bool AreSurroundingTilesEmpty(int startIndex, int length, int directionOffset);
    bool InsertShip(int startIndex, int length, int directionOffset);
public:
    GridMap();
    bool TryPlaceShip(Ship ship);
    bool IsEmpty(int gridIndex);
    void SetTile(int gridIndex, char marker);
    void DisplayGrid();
    char Attack(int attackIndex);
};
