#include <iostream>
#include "./include/SDL2/SDL.h"
#include "./include/renderWindow.h"
#include "./include/Entity.h"
#include "./include/SDL2/SDL_image.h"
#include "./include/misc.h"
#include "./include/Char.h"
#include "./include/PC.h"
#include "./include/Text.h"
using namespace std;

SDL_Event event;

const int WIDTH = 800, HEIGHT = 600;
const int FPS = 60;
const int frameDelay = 1000 / FPS;
const int animDelay = 1000 / 10;

Uint32 frameStart;
int frameTime;
int main(int argc, char *argv[])
{
    /*============================================ INIT ===================================*/
    RenderWindow Window("Game v1.0", WIDTH, HEIGHT); // CPP Construction

    SDL_Texture *grassTexture = Window.loadTexture("../Res/gfx/grass.png");
    SDL_Texture *NPC_IdleTexutre = Window.loadTexture("../Res/gfx/Idle_PC.png");
    SDL_Texture *NPC_WalkTexutre = Window.loadTexture("../Res/gfx/Walk_PC.png");
    SDL_Texture *SkyboxTexture = Window.loadTexture("../Res/gfx/sky.png");
    //==================================== Render ground (aka platform)===============================
    Entity ground[] = {
        Entity(0, 0, 800, 600, grassTexture),
        Entity(32, 0, 800, 600, grassTexture),
        Entity(100, 300, 800, 600, grassTexture),
    };
    Entity skyBox = {0, 0, 656, 518, SkyboxTexture};
    Char npc = Char(60, 50, 32, 32, NPC_IdleTexutre);
    PC PlayerChar = PC(100, 400, 32, 32, NPC_IdleTexutre);
    Text Txt_score = Text("../Res/dev/font/font.ttf", "Score: placeHolder", 350, 10, 200, 200);

    /*================================== SDL LOOP==============================================*/

    bool bGameRunning = true;
    int xDir = 0, yDir = 0;
    bool bDash, bshowLog, bGetInput = false;
    while (bGameRunning)
    {
        frameStart = SDL_GetTicks();
        EventHandler(event, bGameRunning, xDir, yDir, bDash, bGetInput, bshowLog);

        Window.Clear();
        Window.Render(skyBox, 800);
        Txt_score.Update();

        for (int i = 0; i < sizeof(ground) / sizeof(ground[0]); i++)
        {
            Window.Render(ground[i], 32);
        }
        SDL_Texture *curTex = NPC_IdleTexutre;
        if (xDir != 0)
        {
            curTex = NPC_WalkTexutre;
            Txt_score.refresh();
            Txt_score.Update("1234");
        }
        PlayerChar.handleInput(xDir, yDir, bDash, NPC_IdleTexutre, NPC_WalkTexutre);

        if (animDelay > SDL_GetTicks() - frameStart)
        {
            SDL_Delay(animDelay - (SDL_GetTicks() - frameStart));
            npc.LoadAnimation(curTex);
            PlayerChar.LoadAnimation(PlayerChar.GetTexture());
        }
        Window.Render(Window.Surface2Texture(Txt_score.getSurface()), Txt_score.getRect());
        Window.Render(PlayerChar, 64 * 2, PlayerChar.getBFlip());
        Window.Render(npc, 128 * 2);
        Window.Display();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    Txt_score.clean();
    Window.cleanUp();
    SDL_Quit();
    return 0;
}
