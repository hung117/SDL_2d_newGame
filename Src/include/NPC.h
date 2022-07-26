#pragma once
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include "./Char.h"
class NPC : public Char
{
public:
    using Char::Char;
    float checkDistance(SDL_Rect *_destRect);
    void Patrol(); // Walk Randomly
    void RunAway();
    void Behavior(SDL_Texture *_Idle, SDL_Texture *_Walk, SDL_Texture *_Attack);
    bool getBFlip();

protected:
    SDL_Rect *target;
    float distance2PC;
    int xDir = 0;
    int yDir = 0;
    bool bflip = false;
};