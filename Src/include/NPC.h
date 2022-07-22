#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include <./Entity.h>
class NPC : public Entity
{
public:
    using Entity::Entity;
    void setRectX(int x);
    void LoadAnimation(SDL_Texture *_Texture);
    // void LoadAnimation();
    SDL_Texture *SetTexture();
};