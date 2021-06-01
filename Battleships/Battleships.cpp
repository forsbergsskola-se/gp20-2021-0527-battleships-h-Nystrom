#include "GridMap.h"

int main(){
    auto gridMap = new GridMap();
    gridMap->DisplayGrid();
    gridMap->SetTile(10, 'f');
    gridMap->GetTileInfo(10);
    gridMap->DisplayGrid();
    return 0;
}
//TODO: Placement of ships logic:
//Current player: (text)
//Current Ship info (text)
//Pick index: A5 etc... (input)
//Rotate? y/n... (input)
//Check if it's doable (repeat or continue)
//
//TODO: Pick pvp or vs bot
//TODO: P1 picks location for battleships
//TODO: P2 picks location for battleships
//TODO: P1 ship grid and attacking grid
//TODO: p2 ship grid and attacking grid
///Summary
///
///MapGrid Y:0-9 X:A-J
///
///2players turn based
///
///ships 5, 4, 3, 2,2 
///
///
///Class ship:
///name
///size
///Placement: Vertically and horizontally
///Overlap checks and cant connect with each other
///
///Carrier: 5
///Battleship: 4
///Destroyer: 3
///Submarine: 2
///Patrol boat: 2
///
///
///Player:
///Codinates g7, a2 etc
///
///Feedback Hit, miss, ship sunk.
///
