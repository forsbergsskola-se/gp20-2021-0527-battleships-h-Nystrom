#include "GridMap.h"
#include <iostream>

GridMap::GridMap(){
    gridArray[100];
    std::fill_n(gridArray, 100, ' ');
}
bool GridMap::IsEmpty(const int gridIndex){
    return gridArray[gridIndex] == ' ';
}

char GridMap::GetTileInfo(const int gridIndex){
    return gridArray[gridIndex];
}
void GridMap::SetTile(const int gridIndex, const char marker){
    if(gridIndex < 100 && gridIndex >= 0)
        gridArray[gridIndex] = marker;
}
void GridMap::DisplayTopRow(){
    char topRow[]{'*', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','J', 'K'};
    for (int i = 0; i <= 10; i++){
        std::cout << '[' << topRow[i] << ']';
    }
    std::cout << "" << std::endl;
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






//S = ship, " " = empty, O = miss, X hit.
//
//GridMap target Visuals:
//
//[*][A][B][C][D][E][F][G][H][I][J]
//[0][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[1][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[2][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[3][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[4][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[5][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[6][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[7][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[8][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[9][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//
//Player x's turn to attack: [9][J] 