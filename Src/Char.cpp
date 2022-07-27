#include "./include/Char.h"
Char::Char(int _speed, int _boxW, int _boxH, float _x, float _y, int srcW, int srcH) : Entity(_x, _y, srcW, srcH)
{
    colBox.x = position.x;
    colBox.y = position.y;
    colBox.w = _boxW;
    colBox.h = _boxH;
    moveSpeed = _speed;
}
Char::Char(int _speed, int _boxW, int _boxH, float _x, float _y, SDL_Texture *pTex) : Entity(_x, _y, pTex)
{
    colBox.x = position.x;
    colBox.y = position.y;
    colBox.w = _boxW;
    colBox.h = _boxH;
    moveSpeed = _speed;
}

void Char::setRectX(int _x)
{
    this->rect_curFrame.x = position.x;
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
void Char::setMoveSpeed(int _speed)
{
    moveSpeed = _speed;
}
int Char::getMoveSpeed()
{
    return moveSpeed;
}
void Char::Loop()
{
    if (bCollided)
    {
        std::cout << "prevX: " << prevPos[0] << ", prevY: " << prevPos[1] << "x: " << position.x << ", y: " << position.y << std::endl;
        position.x = prevPos[0];
        position.y = prevPos[1];
    }
    else
    {
        prevPos[0] = position.x;
        prevPos[1] = position.y;
    }

    colBox.x = position.x;
    colBox.y = position.y;
}
SDL_Rect *Char::getColBox()
{
    return &colBox;
}
bool Char::detectCollision(SDL_Rect *a, SDL_Rect *b)
// bool Char::detectCollision(SDL_Rect &a, SDL_Rect &b)
{
    // if (a->x < 0)
    if (this->getX() < 0)
    {
        // a->x = 800;
        this->setX(800 - a->w);
    }
    if ((a->x + a->w) > 800)
    {
        // a->x = 0;
        this->setX(0);
    }
    if ((a->y + a->h) > 600)
    {
        // a->y = 0;
        this->setY(0);
    }
    // if (a->y < 0)
    if (this->getY() < 0)
    {
        // a->y = 600;
        this->setY(600 - a->h);
    }
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // Calculate the sides of rect A
    leftA = a->x;
    rightA = a->x + a->w;
    topA = a->y;
    bottomA = a->y + a->h;

    // Calculate the sides of rect B
    leftB = b->x;
    rightB = b->x + b->w;
    topB = b->y;
    bottomB = b->y + b->h;
    // If any of the sides from A are outside of B

    if (bottomA <= topB)
    {
        bCollided = false;

        return false;
    }

    if (topA >= bottomB)
    {
        bCollided = false;

        return false;
    }

    if (rightA <= leftB)
    {
        bCollided = false;

        return false;
    }

    if (leftA >= rightB)
    {
        bCollided = false;

        return false;
    }
    // If none of the sides from A are outside B
    bCollided = true;
    return true;
}
bool Char::getBcollided()
{
    return this->bCollided;
}