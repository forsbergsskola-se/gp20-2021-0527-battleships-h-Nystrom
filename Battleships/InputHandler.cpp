﻿#include "stdafx.h"
#include "InputHandler.h"


//TODO: If I have time refactor duplication...
void InputHandler::EndCurrentTurn(int playerId){
    for(int i = 0; i < 2; i++){
        int playerInput;
        cout << "Player" << playerId << " press enter!" << endl;
        cin >> noskipws >> playerInput;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        playerId++;
    }
    system("CLS");
}

bool InputHandler::SimpleRequest(const char trueChar, const char falseChar, const string message){
    while (true){
        char playerInput;
        cout << message << endl;
        cin >> noskipws >> playerInput;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(playerInput == trueChar)
            return true;
        if(playerInput == falseChar)
            return false;
        
        cout << "Input needs to be: " << trueChar << ", or: " << falseChar << endl;
    }
}

int InputHandler::CoordinateToIndex(const int minValue, const int maxValue, const string message){
    while (true){
        string playerInput;
        cout << message << endl;
        cin >> noskipws >> playerInput;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        const int gridIndex = StringToInt(playerInput, minValue,maxValue);
        if(gridIndex != -1)
            return gridIndex;
        cout << "Error: coordinate doesn't exist!" << endl;
    }
}
int InputHandler::StringToInt(string coordinate, const int minValue, const int maxValue){
    const char offsetChars[]{'a','0'};
    const int rowSize = 10;
    for (int i = 0; i < 2; i++){
        coordinate[i] =  tolower(coordinate[i])-offsetChars[i];
        if(coordinate[i] < minValue || coordinate[i] > maxValue)
            return -1;
    }
    return coordinate[0] + coordinate[1]*rowSize;
}

