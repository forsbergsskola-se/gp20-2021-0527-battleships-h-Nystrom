﻿#include "InputHandler.h"

#include <iostream>


bool InputHandler::SimpleRequest(const char trueChar, const char falseChar, const std::string message){
    while (true){
        char playerInput;
        std::cout << message << std::endl;
        std::cin >> std::noskipws >> playerInput;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(playerInput == trueChar)
            return true;
        if(playerInput == falseChar)
            return false;
        
        std::cout << "Input needs to be: " << trueChar << ", or: " << falseChar << std::endl;
    }
}
//TODO:Refactor!
int InputHandler::CoordinateToIndex(const int minValue, const int maxValue, const std::string message){
    while (true){
        std::string playerInput;
        std::cout << message << std::endl;
        std::cin >> std::noskipws >> playerInput;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        const int temp = StringToInt(playerInput, minValue,maxValue);
        if(temp != -1)
            return temp;
        std::cout << "Error: coordinate doesn't exist!" << std::endl;
    }
}
int InputHandler::StringToInt(std::string coordinate, const int minValue, const int maxValue){
    const char offsetChars[]{'a','0'};
    const int rowSize = 10;
    for (int i = 0; i < 2; i++){
        coordinate[i] = std:: tolower(coordinate[i])-offsetChars[i];
        if(coordinate[i] < minValue || coordinate[i] > maxValue)
            return -1;
    }
    return coordinate[0] + coordinate[1]*rowSize;
}

