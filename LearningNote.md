# Game

use
`C:\Users\BDHung\Desktop\C_Document\Uni_Misc\Current\LTNC\BTL\Game\SDL_2d_newGame\exe\game.exe`
to run game via cmd

### pragma once error

You get the warning because you are compiling a file that contains #pragma once. #pragma once is only intended to be used in headers, and there is no need to compile headers; hence the warning. Solution: Don't compile headers.

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
