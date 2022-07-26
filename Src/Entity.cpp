#include "./include/Entity.h"
using namespace std;
Entity::Entity(float _x, float _y, int _w, int _h, SDL_Texture *pTex)
    : x(_x), y(_y), pTex(pTex)
{
    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = _w;
    rect_curFrame.h = _h;
}
Entity::Entity(float _x, float _y, SDL_Texture *pTex) : x(_x), y(_y), pTex(pTex)
{
    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = 0;
    rect_curFrame.h = 0;
}

Entity::Entity(float _x, float _y, int _w, int _h)
    : x(_x), y(_y)
{
    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = _w;
    rect_curFrame.h = _h;
}
Entity::Entity(float _x, float _y)
    : x(_x), y(_y)
{
}

float Entity::getX()
{
    return x;
}
float Entity::getY()
{
    return y;
}
void Entity::setX(int _x)
{
    this->x = _x;
}
void Entity::setY(int _y)
{
    this->y = _y;
}
SDL_Texture *Entity::GetTexture()
{
    return pTex;
}
SDL_Rect Entity::getCurFrame()
{
    return rect_curFrame;
}
