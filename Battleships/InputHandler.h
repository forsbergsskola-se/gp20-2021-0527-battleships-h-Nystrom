#pragma once
#include <string>

class InputHandler{
public:
    static bool SimpleRequest(char trueChar, char falseChar, std::string message);
    static int CoordinatesToIndex(int minValue,int maxValue, std::string message);
};
