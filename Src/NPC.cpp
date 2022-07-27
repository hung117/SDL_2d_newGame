#include "./include/NPC.h"
#include <cmath>
float NPC::checkDistance(SDL_Rect *_destRect)
{
    target = _destRect;
    distance2PC = sqrt(pow((_destRect->x - position.x), 2) + pow((_destRect->y - position.y), 2));
    std::cout << "Distance: " << distance2PC << std::endl;

    return distance2PC;
}
bool NPC::getBFlip()
{
    return this->bflip;
}
void NPC::Patrol()
{
    srand(time(NULL));
    // xDir = (rand() % 3) + 1;
    xDir = 1;
    yDir = (rand() % 3) + 1;
}
void NPC::RunAway()
{
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
void NPC::Behavior(SDL_Texture *_Idle, SDL_Texture *_Walk, SDL_Texture *_Attack)
{
    Patrol();
    if (xDir == 0 || yDir == 0)
    {
        // LoadAnimation(_Idle);
        pTex = _Idle;
    }
    else
    {
        // LoadAnimation(_Walk);

        pTex = _Walk;
        if (distance2PC < 50)
        {
            RunAway();
        }
        bflip = false;
        if (xDir < 0)
        {
            bflip = true;
        }
        float xPos = position.x + moveSpeed * xDir;
        if (bCollided)
        {
            xDir *= -1;
            // yDir *= -1;
        }

        float yPos = position.y + moveSpeed * yDir;
        position.setVector2(xPos, yPos);
        // setPos(xPos, yPos);
        colBox.x = position.x;
        colBox.y = position.y;
    }
}
