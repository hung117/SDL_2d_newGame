#include "./include/Text.h"
// Text::Text(string fontPath, string _strTxt) : Entity(float _x, float _y, int _w, int _h)
// Text::Text(string fontPath, string _strTxt) : Entity(_x, _y, _w, _h)
// Text::Text(string fontPath, string _strTxt) : Entity(x, y, w, h)
// Text::Text(string fontPath, string _strTxt, float _x, float _y, int _w, int _h) : Entity(_x, _y, _w, _h)
Text::Text(string fontPath, string _strTxt, float _x, float _y) : Entity(_x, _y)
{
    if (TTF_Init() < 0)
    {
        cout << "Error intializing SDL_ttf: " << TTF_GetError() << endl;
        return;
    }
    font = TTF_OpenFont(fontPath.c_str(), 50);
    if (!font)
    {
        cout << "Error loading font: " << TTF_GetError() << endl;
        return;
    }
    // SDL_Color foreground = {125, 123, 175};
    foreground = {0, 0, 0, 225};
    // pTex = SDL_CreateTextureFromSurface(prenderer, text_surface);
    strTxt = _strTxt;
    // x = _x;
    // y = _y;
    textRect.x = _x;
    textRect.y = _y;
    // textRect.w = _w;
    // textRect.h = _h;
    text_surface = TTF_RenderText_Solid(font, strTxt.c_str(), foreground);
}
void Text::Update(string newStr)
{
    if (newStr == "")
    {
    }
    else
    {
        strTxt = newStr;
        text_surface = TTF_RenderText_Solid(font, strTxt.c_str(), foreground);
    }
    textRect.w = text_surface->w;
    textRect.h = text_surface->h;
}
SDL_Surface *Text::getSurface()
{
    return text_surface;
}
void Text::setTring(string str)
{
    textRect.x = x;
    textRect.y = y;
    textRect.w = text_surface->w;
    textRect.h = text_surface->h;
}
SDL_Rect Text::getRect()
{
    return this->textRect;
}
void Text::clean()
{
    SDL_FreeSurface(text_surface);
    TTF_CloseFont(font);
}
void Text::refresh()
{
    SDL_FreeSurface(text_surface);
}