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

float Entity::getX()
{
    return x;
}
float Entity::getY()
{
    return y;
}
SDL_Texture *Entity::GetTexture()
{
    return pTex;
}
SDL_Rect Entity::getCurFrame()
{
    return rect_curFrame;
}
