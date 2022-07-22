#include "./include/NPC.h"
NPC::NPC(float _x, float _y, int _w, int _h, SDL_Texture *pTex)
    : x(_x), y(_y), pTex(pTex)
{
    rect_curFrame.x = 0;
    rect_curFrame.y = 0;
    rect_curFrame.w = _w;
    rect_curFrame.h = _h;
}
float NPC::getX()
{
    return x;
}
float NPC::getY()
{
    return y;
}
void NPC::setX(int _x)
{
    SDL_Rect newrect;

    newrect.x = _x;
    newrect.y = rect_curFrame.y;
    newrect.w = rect_curFrame.w;
    newrect.h = rect_curFrame.h;
    // this->rect_curFrame.x = x;
    rect_curFrame = newrect;
}
float NPC::setY()
{
    return y;
}
void NPC::LoadAnimation()
{
    if (this->rect_curFrame.x >= 96)
    {
        this->rect_curFrame.x = 0;
        return;
    }
    this->rect_curFrame.x += 32;
    // std::cout << "this->rect_curFrame.x: " << this->rect_curFrame.x << std::endl;
    SDL_Rect newrect;
    newrect.x = rect_curFrame.x;
    newrect.y = rect_curFrame.y;
    newrect.w = rect_curFrame.w;
    newrect.h = rect_curFrame.h;
    rect_curFrame = newrect;
    std::cout << "NPC: " << std::endl
              << "rect.x: " << newrect.x << " curframe.x: " << rect_curFrame.x << std::endl;
}
SDL_Texture *NPC::GetTexture()
{
    return pTex;
}
SDL_Rect NPC::getCurFrame()
{
    return rect_curFrame;
}