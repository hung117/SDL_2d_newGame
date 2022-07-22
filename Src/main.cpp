#include <iostream>
#include "./include/SDL2/SDL.h"
#include "./include/renderWindow.h"
#include "./include/Entity.h"
#include "./include/SDL2/SDL_image.h"
#include "./include/misc.h"
#include "./include/NPC.h"
using namespace std;

SDL_Event event;

const int WIDTH = 800, HEIGHT = 600;
const int FPS = 30;
const int frameDelay = 1000 / FPS;
const int animDelay = 1000 / 10;
Uint32 frameStart;
int frameTime;
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
    RenderWindow Window("Game v1.0", WIDTH, HEIGHT); // CPP Construction

    SDL_Texture *grassTexture = Window.loadTexture("../Res/gfx/grass.png");
    SDL_Texture *NPC_IdleTexutre = Window.loadTexture("../Res/gfx/Idle_PC.png");
    SDL_Texture *SkyboxTexture = Window.loadTexture("../Res/gfx/sky.png");
    //==================================== Render ground (aka platform)===============================
    Entity ground[] = {
        Entity(0, 0, 800, 600, grassTexture),
        Entity(32, 0, 800, 600, grassTexture),
        // Entity(100, 300, 800, 600, grassTexture),
    };
    Entity skyBox = {0, 0, 656, 518, SkyboxTexture};
    NPC npc = NPC(60, 50, 32, 32, NPC_IdleTexutre);

    /*================================== SDL LOOP==============================================*/

    bool bGameRunning = true;
    int xDir, yDir = 0;
    bool bDash, bshowLog, bGetInput = false;
    while (bGameRunning)
    {
        frameStart = SDL_GetTicks();
        EventHandler(event, bGameRunning, xDir, yDir, bDash, bGetInput, bshowLog);
        Window.Clear();
        // for (int i = 0; i < 5; i++)
        // {
        //     Window.Render(ground[i], 32);
        // }
        if (animDelay > SDL_GetTicks() - frameStart)
        {
            SDL_Delay(animDelay - (SDL_GetTicks() - frameStart));
            npc.LoadAnimation();
        }
        // Window.Render(skyBox, 800);
        Window.Render(npc, 128 * 2);
        // if (!bshowLog && bGetInput)
        // { // cout << "xDir: " << xDir << ", yDir: " << yDir << ", bDash: " << bDash << endl;
        // }
        Window.Display();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    Window.cleanUp();
    SDL_Quit();
    return 0;
}