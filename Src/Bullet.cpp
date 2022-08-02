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
    colBox.x = position.x;
    colBox.y = position.y;
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
    setPos(PC_Pos->x + 16, PC_Pos->y);
    mYDir = mousePos->y - _y; // _y PC position;
    mXDir /= 700;
    mYDir /= 700;
}

Bullet::Bullet(int _speed, int _boxW, float _despawnTime, float _x, float _y, int srcW, int srcH) : Char(_speed, _boxW, _boxW, _x, _y, srcW, srcH)
{
    despawnTime = _despawnTime;
    bAlive = true;
    bIsBullet = true;
}
