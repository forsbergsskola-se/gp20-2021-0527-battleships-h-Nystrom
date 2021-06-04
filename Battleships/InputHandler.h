#pragma once
#include "stdafx.h"

class InputHandler{
    static int StringToInt(string coordinate, int minValue,int maxValue);
public:
    template<typename TValue>
    static TValue GetInputValue();
    static bool SimpleRequest(char trueChar, char falseChar, string message);
    static int CoordinateToIndex(int minValue,int maxValue, string message);
    static void EndCurrentTurn(int playerId);
};
