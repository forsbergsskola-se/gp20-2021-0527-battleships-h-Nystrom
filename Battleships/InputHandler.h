#pragma once
#include <string>

class InputHandler{
    static int StringToInt(std::string coordinate, int minValue,int maxValue);
public:
    static bool SimpleRequest(char trueChar, char falseChar, std::string message);
    static int CoordinateToIndex(int minValue,int maxValue, std::string message);
    static void EndCurrentTurn(int playerId);
};
