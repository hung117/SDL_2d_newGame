#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include <./Entity.h>
class NPC
{
public:
    NPC(float _x, float _y, int _w, int _h, SDL_Texture *pTex);
    float getX();
    float getY();
    void setX(int x);
    float setY();
    // void LoadAnimation(SDL_Texture &SDL_Texture);
    void LoadAnimation();
    SDL_Texture *GetTexture();
    SDL_Texture *SetTexture();
    SDL_Rect getCurFrame();

private:
    /* data */
    float x, y;
    SDL_Rect rect_curFrame;
    SDL_Texture *pTex;
};
