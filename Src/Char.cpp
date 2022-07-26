#include "./include/Char.h"
Char::Char(int _speed, int _boxW, int _boxH, float _x, float _y, int srcW, int srcH) : Entity(_x, _y, srcW, srcH)
{
    colBox.x = x;
    colBox.y = y;
    colBox.w = _boxW;
    colBox.h = _boxH;
    moveSpeed = _speed;
}
Char::Char(int _speed, int _boxW, int _boxH, float _x, float _y, SDL_Texture *pTex) : Entity(_x, _y, pTex)
{
    colBox.x = x;
    colBox.y = y;
    colBox.w = _boxW;
    colBox.h = _boxH;
    moveSpeed = _speed;
}

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

        std::cout << "prevX: " << prevPos[0] << ", prevY: " << prevPos[1] << "x: " << x << ", y: " << y << std::endl;
        // this->setX(0);
        // this->setY(0);
        // this->setY(prevPos[1] - 10);
        // this->setX(prevPos[0] - 10);
        this->setX(prevPos[0]);
        this->setY(prevPos[1]);
        colBox.x = x;
        colBox.y = y;
        return;
    }
    // prevPos[0] = static_cast<float> x;
    // prevPos[1] = static_cast<float> y;
    prevPos[0] = x;
    prevPos[1] = y;
    colBox.x = x;
    colBox.y = y;
}
SDL_Rect *Char::getColBox()
{
    return &colBox;
}
// SDL_Rect Char::getColBox()
// {
//     return this->colBox;
// }
bool Char::detectCollision(SDL_Rect *a, SDL_Rect *b)
// bool Char::detectCollision(SDL_Rect &a, SDL_Rect &b)
{
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
    bCollided = false;

    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    // If none of the sides from A are outside B
    bCollided = true;
    return true;
}
