#include "stdafx.h"
#include "GridMapGenerator.h"
#include "InputHandler.h"


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
        //TODO: Refactor if I have time!
        while (true){
            cout<< "Player"<< playerId << "'s defence gridMap" << endl;
            defenceGridMaps[playerId].DisplayGrid();
            cout<< "Player"<< playerId << "'s attack gridMap" << endl;
            attackGridMaps[playerId].DisplayGrid();
            
            const int attackIndex = InputHandler().CoordinateToIndex(0,9,
                "Captain give coordinates between A0 to J9 for the next missile strike:");
            const int opponentId = playerId == 0 ? 1 : 0;
            const char hitMarker = defenceGridMaps[opponentId].Attack(attackIndex);
            attackGridMaps[playerId].SetTile(attackIndex, hitMarker);
            
            cout<< "Player"<< playerId << "'s attack gridMap" << endl;
            attackGridMaps[playerId].DisplayGrid();

            if(defenceGridMaps[opponentId].IsDefeated())
                break;
            
            InputHandler().EndCurrentTurn(playerId);
            
            playerId == 0 ? playerId++ : playerId = 0;
        }
        cout << "Player" << playerId << " won!" << endl;
        if(!InputHandler().SimpleRequest('y','n', "Play again? Y/N"))
            break;
        
    }
    cout << "Thanks for playing Battleships" << endl;
    return 0;
}
