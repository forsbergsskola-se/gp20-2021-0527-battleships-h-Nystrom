#pragma once
#include "stdafx.h"
#include "Vector2.h"

struct Ship{
    string name;
    int startPosition = 0;
    int length = 0;
    bool isVertical = false;
    Vector2 GetScale() const;
};

