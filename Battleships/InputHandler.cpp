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
