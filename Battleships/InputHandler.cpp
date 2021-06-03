#include "InputHandler.h"

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
int InputHandler::CoordinatesToIndex(const int minValue, const int maxValue, const std::string message){
    while (true){
        const int rowSize = 10;
        std::string playerInput;
        std::cout << message << std::endl;
        std::cin >> std::noskipws >> playerInput;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        int coordinates[2];
        coordinates[0] = std::tolower(playerInput[0]) - 'a';
        coordinates[1] = playerInput[1] - '0';
        
        if(coordinates[0] < minValue || coordinates[0] > maxValue)
            continue;
        if(coordinates[1]< minValue || coordinates[1] > maxValue)
            continue;
        return coordinates[0] + coordinates[1]*rowSize;
    }
}

