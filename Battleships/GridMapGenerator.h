#pragma once
#include "GridMap.h"

class GridMapGenerator{
    static bool SetShipRotation();
    static int SetShipPosition();

public:
    static GridMap SetBattleShips();
    static GridMap GetEmpty();
};
