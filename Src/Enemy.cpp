#include "./include/Enemy.h"
using namespace std;
void Enemy::CHASE()
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

// void Enemy::Behavior(SDL_Texture *_Idle, SDL_Texture *_Walk, SDL_Texture *_Attack)
void Enemy::Behavior(SDL_Texture *_Idle, SDL_Texture *_Walk, SDL_Texture *_Attack)
{
    std::cout << "ENEMY behavior" << endl;
    float xPos = position.x;
    float yPos = position.y;
    Patrol();
    if (distance2PC <= 200)
    {
        CHASE();
    }
    if (xDir == 0 || yDir == 0)
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
            else
            {
                xDir = 1;
                yDir = 1;
            }
        }
    }
    xPos = position.x + moveSpeed * xDir;
    yPos = position.y + moveSpeed * yDir;
    position.setVector2(xPos, yPos);
    colBox.x = position.x;
    colBox.y = position.y;
}
