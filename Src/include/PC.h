#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include <./NPC.h>
class PC : public NPC
{
public:
    using NPC::NPC;
    void handleInput(int _xDir, int _yDir, bool _bDash, SDL_Texture *Idle, SDL_Texture *Walk);
    int getXDir();
    int getYDir();
    bool getBFlip();
    void setXDir(int _xDir);
    void setYDir(int _yDir);

protected:
    int fSpeed = 20;
    int xDir = 0;
    int yDir = 0;
    bool bDash = false;
    bool bflip = false;
};
