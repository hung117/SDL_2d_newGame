#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include "Vector2.h"
class Entity
{
public:
    Entity(float _x, float _y, int _w, int _h, SDL_Texture *pTex);
    Entity(float _x, float _y, SDL_Texture *pTex);
    Entity(float _x, float _y, int _w, int _h);
    Entity(float _x, float _y);
    float getX();
    float getY();
    SDL_Texture *GetTexture();
    SDL_Rect getCurFrame();
    void setX(int _x);
    void setY(int _y);
    void setPos(int _x, int _y);
    Vector2 *getPos();

protected:
    /* data */
    Vector2 position = Vector2(0, 0);
    SDL_Rect rect_curFrame;
    SDL_Texture *pTex;
};
