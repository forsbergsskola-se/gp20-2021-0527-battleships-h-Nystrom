#pragma once
#include "Ship.h"

class GridMap{
    char gridArray[100];
    static void DisplayTopRow();
public:
    GridMap();
    bool TryPlaceShip(Ship ship);
    bool IsEmpty(int gridIndex);
    char GetTileInfo(int gridIndex);
    void SetTile(int gridIndex, char marker);
    void DisplayGrid();
};
