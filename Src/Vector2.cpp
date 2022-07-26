#include "./include/Vector2.h"
Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}
Vector2 *Vector2::getVector2() { return this; }
void Vector2::setVector2(float _x, float _y)
{
    this->x = _x;
    this->y = _y;
}