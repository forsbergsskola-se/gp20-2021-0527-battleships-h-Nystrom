#include "Ship.h"


Vector2 Ship::GetScale() const{
    return  isVertical ? Vector2(3, length+2) : Vector2(length, 3);
}

