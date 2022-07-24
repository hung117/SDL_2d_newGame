#include "./include/Char.h"
void Char::setRectX(int _x)
{
    this->rect_curFrame.x = x;
}
void Char::LoadAnimation(SDL_Texture *_Textures)
// void NPC::LoadAnimation()
{
    this->pTex = _Textures;
    if (this->rect_curFrame.x >= 96)
    {
        this->rect_curFrame.x = 0;
        return;
    }
    this->rect_curFrame.x += 32;
}