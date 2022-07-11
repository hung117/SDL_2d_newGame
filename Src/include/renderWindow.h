#pragma once
#include "./SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
class RenderWindow
{
public:
    RenderWindow(const char *p_Title, int p_w, int p_h);
    SDL_Texture *loadTexture(const char *p_FilePath); // SDL_Texture is created and placed randomly by SDL itself, we dont know what it is so I'm just gonna use the pointer like this :v
    void Clear();
    void Render(SDL_Texture *pTex);
    void Display();
    void cleanUp();

private:
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};