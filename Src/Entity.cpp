#include "./include/Entity.h"
using namespace std;
Entity::Entity(float _x, float _y, int _w, int _h, SDL_Texture *pTex)
    : pTex(pTex)
// : x(_x), y(_y), pTex(pTex)

{
    position = Vector2(_x, _y);
    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = _w;
    rect_curFrame.h = _h;
}
// Entity::Entity(float _x, float _y, SDL_Texture *pTex) : x(_x), y(_y), pTex(pTex)
Entity::Entity(float _x, float _y, SDL_Texture *pTex) : pTex(pTex)
{
    position = Vector2(_x, _y);

    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = 0;
    rect_curFrame.h = 0;
}

Entity::Entity(float _x, float _y, int _w, int _h)
{
    position = Vector2(_x, _y);

    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = _w;
    rect_curFrame.h = _h;
}
Entity::Entity(float _x, float _y)
{
    position = Vector2(_x, _y);
}
Vector2 *Entity::getPos()
{
    return &position;
}
float Entity::getX()
{
    return position.x;
}
float Entity::getY()
{
    return position.y;
}
void Entity::setX(int _x)
{
    position.x = _x;
    // this->x = _x;
}
void Entity::setY(int _y)
{
    position.y = _y;
    // this->y = _y;
}
void Entity::setPos(int _x, int _y)
{
    position.x = _x;
    position.y = _y;
}
SDL_Texture *Entity::GetTexture()
{
    return pTex;
}
SDL_Rect Entity::getCurFrame()
{
    return rect_curFrame;
}
