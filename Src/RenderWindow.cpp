#include "./include/SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./include/Entity.h"
#include "./include/renderWindow.h"
#include "./include/Char.h"
#include <iostream>
using namespace std;
RenderWindow::RenderWindow(const char *p_Title, int p_W, int p_H) : pWindow(NULL), pRenderer(NULL)
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
SDL_Texture *RenderWindow::loadTexture(const char *pFilePath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(pRenderer, pFilePath);
    if (texture == NULL)
    {
        cout << "Failed to load Texture" << SDL_GetError() << endl;
    }
    return texture;
}
SDL_Texture *RenderWindow::Surface2Texture(SDL_Surface *_surface)
{
    return SDL_CreateTextureFromSurface(pRenderer, _surface);
}
void RenderWindow::Clear()
{
    SDL_RenderClear(pRenderer);
}
SDL_Renderer *RenderWindow::getRenderer()
{
    return pRenderer;
}
void RenderWindow::Render(Entity &p_Entity, int dstSize, bool flip)
// void RenderWindow::Render(Entity &p_Entity, int dstSize, bool flip = false)
{
    SDL_Rect src;
    src.x = p_Entity.getCurFrame().x;
    src.y = p_Entity.getCurFrame().y;
    src.w = p_Entity.getCurFrame().w;
    src.h = p_Entity.getCurFrame().h;
    // cout << "x: " << src.x << " p_Entity.getCurFrame().x: " << p_Entity.getCurFrame().x << endl;

    SDL_Rect dest;
    dest.x = p_Entity.getX();
    dest.y = p_Entity.getY();
    dest.w = dstSize;
    dest.h = dstSize;
    if (src.w == 0 || src.h == 0)
    {
        SDL_RenderCopy(pRenderer, p_Entity.GetTexture(), nullptr, &dest);
        return;
    }
    if (flip)
    {
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
        // SDL_RenderCopy(pRenderer, p_Entity.GetTexture(), &src, &dest, flip);
        SDL_RenderCopyEx(pRenderer, p_Entity.GetTexture(), &src, &dest, 0.0f, nullptr, flip);
        return;
    }
    SDL_RenderCopy(pRenderer, p_Entity.GetTexture(), &src, &dest);
}

// void RenderWindow::Render(SDL_Texture *_texture, SDL_Rect &_rect)
void RenderWindow::Render(SDL_Texture *_texture, SDL_Rect _rect)
{
    SDL_RenderCopy(pRenderer, _texture, nullptr, &_rect);
}
void RenderWindow::Display()
{
    SDL_RenderPresent(pRenderer);
}
void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(pWindow);
}
