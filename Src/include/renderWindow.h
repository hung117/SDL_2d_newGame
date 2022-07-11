#pragma once
#include "./SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
class RenderWindow
{
public:
    RenderWindow(const char *p_Title, int p_w, int p_h);
    // RenderWindow(string p_Title,int py)
    void cleanUp();

private:
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};