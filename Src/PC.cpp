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
        // if (this->getX() > 800)
        // {
        //     this->setX(0);
        // }
        // if (this->getX() < 0)
        // {
        //     this->setX(800);
        // }
        // if (this->getY() > 600)
        // {
        //     this->setY(0);
        // }
        // if (this->getY() < 0)
        // {
        //     this->setY(600);
        // }
        int Xposition = this->xDir * moveSpeed + (int)this->getX();
        int yposition = this->yDir * -1 * moveSpeed + (int)this->getY();
        // setX(Xposition);
        // setY(yposition);
        setPos(Xposition, yposition);
        colBox.x = position.x;
        colBox.y = position.y;
        // std::cout << "XDir: " << xDir << " yDIr: " << yDir << std::endl;
        pTex = Walk;
    }
    else
    {
        pTex = Idle;
    }
}