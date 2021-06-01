#pragma once

class GridMap{
    char gridArray[100];
    static void DisplayTopRow();
public:
    GridMap();
    bool IsEmpty(int gridIndex);
    char GetTileInfo(int gridIndex);
    void SetTile(int gridIndex, char marker);
    void DisplayGrid();
};
