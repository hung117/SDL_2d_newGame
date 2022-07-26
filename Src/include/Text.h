#pragma once
#include <iostream>
#include <./SDL2/SDL.h>
#include <./Entity.h>
#include "./SDL2/SDL_ttf.h"
#include <string.h>
#include <strings.h>
using namespace std;

class Text : public Entity
{
public:
    // Text(string fontPath, string _strTxt = "", float _x, float _y, int _w, int _h);
    Text(string fontPath, string _strTxt, float _x, float _y, int _w, int _h);
    Text(string fontPath, string _strTxt, float _x, float _y);
    string getString();
    TTF_Font *getFont();
    void setFont(TTF_Font *font);
    void setTring(string str);
    SDL_Surface *getSurface();
    SDL_Rect getRect();
    void Update(string _newInput = "");
    void refresh();
    void clean();

private:
    string strTxt;
    TTF_Font *font;
    SDL_Surface *text_surface;
    SDL_Rect textRect;
    SDL_Color foreground;
};