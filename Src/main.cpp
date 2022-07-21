#include <iostream>
#include "./include/SDL2/SDL.h"
#include "./include/renderWindow.h"
#include "./include/Entity.h"
#include "./include/SDL2/SDL_image.h"
#include "./include/misc.h"
using namespace std;

SDL_Event event;

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{
    /*============================================ INIT ===================================*/
    // SDL_Init(SDL_INIT_EVERYTHING);
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        cout << "IMG_Init has failed" << SDL_GetError() << endl;
        return 1;
    }
    if ((SDL_Init(SDL_INIT_VIDEO) > 0))
    {
        cout << "SDL_Video_Init has failed" << SDL_GetError() << endl;
        return 1;
    }
    // SDL_Surface *gScreenSurface = NULL;
    RenderWindow Window("Game v1.0", 1280, 720); // CPP Construction
    // RenderWindow Window = new RenderWindow("Game v1.0", 1280, 720); doesnt work with cpp
    // SDL_Event event;
    SDL_Texture *grassTexture = Window.loadTexture("../Res/gfx/grass.png");
    //==================================== Render ground (aka platform)===============================
    Entity ground[] = {
        Entity(0, 0, grassTexture),
        Entity(23, 0, grassTexture),
        Entity(23, 23, grassTexture),
        Entity(0, 23, grassTexture),
        Entity(100, 300, grassTexture),
    };
    /*================================== SDL LOOP==============================================*/

    bool bGameRunning = true;
    while (bGameRunning)
    {
        EventHandler(event, bGameRunning);
        Window.Clear();
        // Window.Render(ground);
        for (int i = 0; i < 5; i++)
        {
            Window.Render(ground[i]);
        }

        Window.Display();
    }
    Window.cleanUp();
    SDL_Quit();
    return 0;
}