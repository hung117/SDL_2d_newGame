#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include <./Entity.h>
class Bullet : public Char
{
public:
    // using Char::Char;
    Bullet(int _speed, int _boxW, float despawnTime, float _x, float _y, int srcW, int srcH);
    void Call(Vector2 *mousePos, Vector2 *PC_Pos);
    void Loop();
    void Behavior(SDL_Texture *_bullet);

protected:
    bool bBullet = true;
    bool bAlive = true;
    float despawnTime;
    float mXDir, mYDir;

private:
    int curTime = 0;
};