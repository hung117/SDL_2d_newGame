#include "./include/SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./include/renderWindow.h"
#include <iostream>
using namespace std;
RenderWindow::RenderWindow(const char *p_Title, int p_W, int p_H)
{
    pWindow = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, p_W, p_H, SDL_WINDOW_SHOWN);
    if (pWindow == NULL)
    {
        std::cout << "Window failed to be inited." << SDL_GetError() << endl;
    }
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == NULL)
    {
        std::cout << "Renderer failed to be inited." << SDL_GetError() << endl;
    }
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(pWindow);
}