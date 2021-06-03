#include <iostream>
#include "GridMapGenerator.h"

int main(){
    auto gridMapPlayer1 = GridMapGenerator().SetBattleShips();
    gridMapPlayer1.DisplayGrid();
    return 0;
}
