#include "./include/PC.h"
int PC::getXDir()
{
    return xDir;
}
int PC::getYDir()
{
    return yDir;
}
void PC::setXDir(int _xDir)
{
    this->xDir = _xDir;
}
void PC::setYDir(int _yDir)
{
    this->yDir = _yDir;
}
bool PC::getBFlip()
{
    return this->bflip;
}

void PC::handleInput(int _xDir, int _yDir, bool _bDash, SDL_Texture *Idle, SDL_Texture *Walk)
{
    setXDir(_xDir);
    setYDir(_yDir);
    if (_xDir != 0 || _yDir != 0)
    {
        if (xDir < 0)
        {
            bflip = true;
        }
        else
        {
            bflip = false;
        }
        int Xposition = this->xDir * moveSpeed + (int)this->getX();
        int yposition = this->yDir * -1 * moveSpeed + (int)this->getY();
        setPos(Xposition, yposition);
        colBox.x = position.x;
        colBox.y = position.y;
        pTex = Walk;
    }
    else
    {
        pTex = Idle;
    }
}
int PC::checkHit(bool _bHostile) // HIT BY HOSTILE
{
    if (bCollided && _bHostile)
    {
        std::cout << "PC COLLIDED WITH HOSTILE" << std::endl;
        return 1; // PC DIE
    }
    else if (bCollided && !_bHostile)
    {
        std::cout << "PC COLLIDED WITH HOSTILE" << std::endl;
        return 2; // FROG DIE
    }
    return 0; // DEFAULT, NOTHING HAPPENS
}