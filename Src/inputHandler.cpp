#include <iostream>
#include "./include/SDL2/SDL.h"
#include "./include/misc.h"
using namespace std;

void EventHandler(SDL_Event &event, bool &bGameRunning)
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
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    cout << "w";
                    break;
                case SDLK_a:
                    cout << "a";
                    break;
                case SDLK_d:
                    cout << "d";
                    break;
                case SDLK_s:
                    cout << "s";
                    break;
                case SDLK_SPACE:
                    cout << "space";
                    break;
                }
                cout << "--down" << endl;
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    cout << "w";
                    break;
                case SDLK_a:
                    cout << "a";
                    break;
                case SDLK_d:
                    cout << "d";
                    break;
                case SDLK_s:
                    cout << "s";
                    break;
                case SDLK_SPACE:
                    cout << "space";
                    break;
                }
                cout << "--up" << endl;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    cout << "left";
                    break;
                case SDL_BUTTON_RIGHT:
                    cout << "right";
                    break;
                }
                cout << "--click" << endl;
                break;
            default:
                break;
            }
        }
    }
}