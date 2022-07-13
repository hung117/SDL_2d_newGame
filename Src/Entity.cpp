#include "./include/Entity.h"
Entity::Entity(float _x, float _y, SDL_Texture *pTex)
    : x(_x), y(_y), pTex(pTex)
{
    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = 600;
    rect_curFrame.h = 500;
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