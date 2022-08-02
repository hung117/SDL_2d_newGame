#include "Char.h"
#include "Bullet.h"
void Bullet::Loop()
{
    curTime++;
    if (curTime >= despawnTime)
    {
        bAlive = false;
        return;
    }
    bAlive = true;
    this->setPos(this->getX() + mXDir * moveSpeed, this->getY() + mYDir * moveSpeed);
}
void Bullet::Behavior(SDL_Texture *_bullet)
{
    pTex = _bullet;
}
void Bullet::Call(Vector2 *mousePos, Vector2 *PC_Pos)
{
    curTime = 0;
    float _x = PC_Pos->x;
    float _y = PC_Pos->y;
    mXDir = mousePos->x - _x; // _x PC position;
    setPos(PC_Pos->x, PC_Pos->y);
    if (mXDir > 0)
    {
        mXDir = 1;
    }
    else if (mXDir < 0)
    {
        mXDir = -1;
    }
    mYDir = mousePos->y - _y; // _y PC position;
    if (mYDir > 0)
    {
        mYDir = 1;
    }
    else if (mYDir < 0)
    {
        mYDir = -1;
    }
}

Bullet::Bullet(int _speed, int _boxW, float _despawnTime, float _x, float _y, int srcW, int srcH) : Char(_speed, _boxW, _boxW, _x, _y, srcW, srcH)
{
    despawnTime = _despawnTime;
    bAlive = true;
    bIsBullet = true;
}
