#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./SDL2/SDL_image.h>
#include <./Char.h>
class PC : public Char
{
public:
    using Char::Char;
    void handleInput(int _xDir, int _yDir, bool _bDash, SDL_Texture *Idle, SDL_Texture *Walk);
    int getXDir();
    int getYDir();
    bool getBFlip();
    void setXDir(int _xDir);
    void setYDir(int _yDir);

protected:
    int xDir = 0;
    int yDir = 0;
    bool bDash = false;
    bool bflip = false;
};
