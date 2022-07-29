#pragma once
#include "./NPC.h"
class Enemy : public NPC
{
public:
    using NPC::NPC;
    void CHASE(); // Walk Randomly
    void Behavior(SDL_Texture *_Idle, SDL_Texture *_Walk, SDL_Texture *_Attack);

protected:
};