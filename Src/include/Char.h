#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include <./Entity.h>
class Char : public Entity
{
public:
    using Entity::Entity;
    Char(int _speed, int _boxW, int _boxH, float _x, float _y, int srcW, int srcH);
    Char(int _speed, int _boxW, int _boxH, float _x, float _y, SDL_Texture *pTex);
    void setRectX(int x); // select the texture part;
    void LoadAnimation(SDL_Texture *_Texture);
    // void LoadAnimation();
    // bool detectCollision(SDL_Rect &a, SDL_Rect &b);
    bool detectCollision(SDL_Rect *a, SDL_Rect *b);
    SDL_Texture *SetTexture();
    // SDL_Rect getColBox();
    SDL_Rect *getColBox();
    int getMoveSpeed();
    void setMoveSpeed(int _speed);
    void Loop();
    bool getBcollided();

protected:
    float prevPos[2];
    bool bCollided = false;
    int moveSpeed;
    SDL_Rect colBox;
    int BoxWidth;
    int BoxHeight;
};