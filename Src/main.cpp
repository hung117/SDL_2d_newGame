#include <iostream>
#include "./include/SDL2/SDL.h"
// #include "./include/renderWindow.h"
#include "./include/SDL2/SDL_image.h"

using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("HELLO SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == NULL || !(IMG_Init(IMG_INIT_PNG)))
    // if (window == NULL)
    {
        cout << "Can't creat window" << SDL_GetError() << endl;
        return 1;
    }
    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;

    return 0;
}