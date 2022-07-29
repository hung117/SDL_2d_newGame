# Game

use
`C:\Users\BDHung\Desktop\C_Document\Uni_Misc\Current\LTNC\BTL\Game\SDL_2d_newGame\exe\game.exe`
to run game via cmd

### pragma once error

You get the warning because you are compiling a file that contains #pragma once. #pragma once is only intended to be used in headers, and there is no need to compile headers; hence the warning. Solution: Don't compile headers.

# SDL

## Render & Display

what the render do is:
The "Renderer" is basically a canvas.
copy a bunch of texture and mapping them to a canvas as instructed via SDL_RenderCopy.
SDL then uses that said canvas to display that canvas to window via SDL_RenderPresent.

# HEADER

## CLASS IN HEADER

fefine class structure in header
redefine said class in a different cpp by include the header file and using the "class::Method" to select the class and method()
_in HEADER.h_

```
class RenderWindow
{
public:
    RenderWindow(const char *p_Title, int p_w, int p_h);
    void cleanUp();

private:
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};
```

_in CPP.cpp_

```
#include "./HEADER.h"

RenderWindow::RenderWindow(const char *p_Title, int p_W, int p_H)
{
    // DO SOMETHING
}
```

call that class by creating object using constructor:
` RenderWindow Window("Game v1.0", 1280, 720); // CPP Construction`
create a 'RenderWindow' object named 'Window' with following parameter: '("Game v1.0", 1280, 720)'

### Initializer List

Initializer List is used in initializing the data members of a class <br>
`RenderWindow::RenderWindow(const char *p_Title, int p_W, int p_H)` <ins> : pWindow(NULL), pRenderer(NULL)</ins>
the `: pWindow(NULL), pRenderer(NULL)` is the initialize list to assign the class variable value;

### Function

#### Optional parameter

only need in header, the cpp file dont have it.
Eg:
in header.h: ` void Render(Entity &p_Entity, int dstSize, bool flip = false);`<br>
in src.cpp: `void RenderWindow::Render(Entity &p_Entity, int dstSize, bool flip)`

# Array

## Array of class objects

with "Entity" as a class, you can have class allocation right inside the array to create it's object.<br>
_like this:_

```
    Entity ground[] = {
        Entity(0, 0, grassTexture),
        Entity(23, 0, grassTexture),
        Entity(23, 23, grassTexture),
        Entity(0, 23, grassTexture),
        Entity(100, 300, grassTexture),
    };
```

# BUG:

## White screen

Some thing has run out of bound (array for example);

## change in Derived class doesnt really work:

dont write which existed in the parent class to the derived class, because it will make a new variable with the same name instead of the one you intended it to be.

# QUESTION

## function doesnt accept derived class pointer:

```./Src//main.cpp:137:26: error: no matching function for call to 'RenderWindow::Render(Char*&, int&)'
  137 |             Window.Render(StaticList[staticI], StaticList[staticI]->getColBox()->w);
```

## enemy override behavior doesnt work. why ?
