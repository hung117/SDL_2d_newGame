#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
class Entity
{
public:
    Entity(float _x, float _y, SDL_Texture *pTex);
    float getX();
    float getY();
    SDL_Texture *GetTexture();
    SDL_Rect getCurFrame();

private:
    /* data */
    float x, y;
    SDL_Rect rect_curFrame;
    SDL_Texture *pTex;
};
