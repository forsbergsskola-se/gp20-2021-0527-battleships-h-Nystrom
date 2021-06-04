 #include <iostream>
#include "GridMapGenerator.h"
#include "InputHandler.h"

//TODO(1): Fix pre-compiled headers!!
//https://docs.microsoft.com/en-us/cpp/build/creating-precompiled-header-files?view=msvc-160
//TODO(2): validate if a ship is completely gone...
//TODO(3): Search for win in opponents gridMap...
//TODO(4): Clean up, refactoring and bug searching...

int main(){
    while (true){
        int playerId = 0;
        GridMap defenceGridMaps[2];
        GridMap attackGridMaps[2];
        for (int i = 0; i < 2; i++){
            defenceGridMaps[i] = GridMapGenerator().SetBattleShips();
            attackGridMaps[i] = GridMap();
            InputHandler().EndCurrentTurn(playerId);
        }
        //TODO(4): Refactor if I have time!
        while (true){
            std::cout<< "Player"<< playerId << "'s defence gridMap" << std::endl;
            defenceGridMaps[playerId].DisplayGrid();
            std::cout<< "Player"<< playerId << "'s attack gridMap" << std::endl;
            attackGridMaps[playerId].DisplayGrid();
            
            const int attackIndex = InputHandler().CoordinateToIndex(0,9,"Captain give coordinates between A0 to J9 for the next missile strike:");
            const int opponentId = playerId == 0 ? 1 : 0;
            const char hitMarker = defenceGridMaps[opponentId].Attack(attackIndex);
            attackGridMaps[playerId].SetTile(attackIndex, hitMarker);
            
            std::cout<< "Player"<< playerId << "'s attack gridMap" << std::endl;
            attackGridMaps[playerId].DisplayGrid();

            if(defenceGridMaps[opponentId].IsDefeated())
                break;
            
            InputHandler().EndCurrentTurn(playerId);
            
            playerId == 0 ? playerId++ : playerId = 0;
        }
        std::cout << "Player" << playerId << " won!" << std::endl;
        if(!InputHandler().SimpleRequest('y','n', "Play again? Y/N"))
            break;
        
    }
    std::cout << "Thanks for playing Battleships" << std::endl;
    return 0;
}
