#include <iostream>
#include "./include/SDL2/SDL.h"
#include "./include/misc.h"
using namespace std;

void EventHandler(SDL_Event &event, bool &bGameRunning, int &xDir, int &yDir, bool &bSpace, bool &bGetInput, bool &b_debugShow)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            bGameRunning = false;
        }
        else
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                bGetInput = true;
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    if (b_debugShow)
                        cout << "w";
                    yDir = 1;
                    break;
                case SDLK_a:
                    if (b_debugShow)
                        cout << "a";
                    xDir = -1;
                    break;
                case SDLK_d:
                    if (b_debugShow)
                        cout << "d";
                    xDir = 1;
                    break;
                case SDLK_s:
                    if (b_debugShow)
                        cout << "s";
                    yDir = -1;
                    break;
                case SDLK_SPACE:
                    if (b_debugShow)
                        cout << "space";
                    bSpace = true;
                    break;
                case SDLK_RCTRL:
                    b_debugShow = !b_debugShow;
                    break;
                }
                if (b_debugShow)
                    cout << "--down" << endl;
                break;
            case SDL_KEYUP:
                bGetInput = false;
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    if (b_debugShow)
                        cout << "w";
                    yDir = 0;
                    break;
                case SDLK_a:
                    if (b_debugShow)
                        cout << "a";
                    xDir = 0;
                    break;
                case SDLK_d:
                    if (b_debugShow)
                        cout << "d";
                    xDir = 0;
                    break;
                case SDLK_s:
                    if (b_debugShow)
                        cout << "s";
                    yDir = 0;
                    break;
                case SDLK_SPACE:
                    if (b_debugShow)
                        cout << "space";
                    bSpace = false;
                    break;
                }
                if (b_debugShow)
                    cout << "--up" << endl;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if (b_debugShow)
                        cout << "left";
                    break;
                case SDL_BUTTON_RIGHT:
                    if (b_debugShow)
                        cout << "right";
                    break;
                }
                if (b_debugShow)
                    cout << "--click" << endl;
                break;
            default:
                break;
            }
        }
    }
}