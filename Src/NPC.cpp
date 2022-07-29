#include "./include/NPC.h"
#include <time.h>
#include <cmath>
using namespace std;
NPC::NPC(int _speed, int _boxW, int _boxH, float _x, float _y, int srcW, int srcH, bool _bHostile) : Char(_speed, _boxW, _boxH, _x, _y, srcW, srcH)
{

    bHostile = _bHostile;
}
bool NPC::getBHostile()
{
    return bHostile;
}
void NPC::CHASE()
{
    std::cout << "CHASING" << std::endl;
    if ((target->x - position.x) > 0)
    {
        // In the Right
        xDir = 1;
    }
    else if ((target->x - position.x) < 0)
    {
        // In the Left;
        xDir = -1;
    }
    if ((target->y - position.y) > 0)
    {
        // In the bottom

        yDir = 1;
    }
    else if ((target->y - position.y) < 0)
    {
        // In the upper;
        yDir = -1;
    }
}

float NPC::checkDistance(SDL_Rect *_destRect)
{
    target = _destRect;
    distance2PC = sqrt(pow((_destRect->x - position.x), 2) + pow((_destRect->y - position.y), 2));
    // std::cout << "Distance: " << distance2PC << std::endl;

    return distance2PC;
}
bool NPC::getBFlip()
{
    return this->bflip;
}
void NPC::Patrol()
{
    srand(time(NULL));
    xDir = (rand() % 3) + 1;
    int ranIdx = rand() % 3;
    xDir = moveDir[ranIdx];
    srand(time(NULL));
    ranIdx = rand() % 3;
    yDir = moveDir[ranIdx];
}
void NPC::RunAway()
{
    if ((target->x - position.x) > 0)
    {
        // In the Right
        // cout << " PC IS IN THE RIGHT!" << endl;
        // xDir = 1;
        xDir = -1;
    }
    else if ((target->x - position.x) < 0)
    {
        // In the Left;
        // cout << " PC IS IN THE LEFT!" << endl;

        // xDir = -1;
        xDir = 1;
    }
    if ((target->y - position.y) > 0)
    {
        // In the bottom
        // cout << " PC IS IN THE BOTTOM!" << endl;

        // yDir = 1;
        yDir = -1;
    }
    else if ((target->y - position.y) < 0)
    {
        // In the upper;
        // cout << " PC IS IN THE UPPER!" << endl;

        // yDir = -1;
        yDir = 1;
    }
}
void NPC::Behavior(SDL_Texture *_Idle, SDL_Texture *_Walk, SDL_Texture *_Attack)
{
    float xPos = position.x;
    float yPos = position.y;
    Patrol();
    if (distance2PC <= 200)
    {
        if (bHostile)
        {
            CHASE();
        }
        else
        {
            RunAway();
        }
    }
    if (xDir == 0 && yDir == 0)
    {
        // LoadAnimation(_Idle);
        pTex = _Idle;
    }
    else
    {
        // LoadAnimation(_Walk);
        pTex = _Walk;
        bflip = false;
        if (xDir < 0)
        {
            bflip = true;
        }
    }
    if (bCollided)
    {
        if (xDir != 0)
        {
            xDir *= -1;
        }
        if (yDir != 0)
        {
            yDir *= -1;
        }
    }
    xPos = position.x + moveSpeed * xDir;
    yPos = position.y + moveSpeed * yDir;
    position.setVector2(xPos, yPos);
    colBox.x = position.x;
    colBox.y = position.y;
}
