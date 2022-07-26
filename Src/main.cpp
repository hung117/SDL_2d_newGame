#include <iostream>
#include "./include/SDL2/SDL.h"
#include "./include/renderWindow.h"
#include "./include/Entity.h"
#include "./include/SDL2/SDL_image.h"
#include "./include/misc.h"
#include "./include/Char.h"
#include "./include/PC.h"
#include "./include/Text.h"
#include "./include/NPC.h"
using namespace std;

SDL_Event event;

const int WIDTH = 800, HEIGHT = 600;
const int FPS = 80;
const int frameDelay = 1000 / FPS;
const int animDelay = 1000 / 10;

Uint32 frameStart;
int frameTime;
int main(int argc, char *argv[])
{
    /*============================================ INIT ===================================*/
    RenderWindow Window("Game v1.0", WIDTH, HEIGHT); // CPP Construction

    SDL_Texture *grassTexture = Window.loadTexture("../Res/gfx/grass.png");
    SDL_Texture *PC_IdleTexutre = Window.loadTexture("../Res/gfx/Idle_PC.png");
    SDL_Texture *PC_WalkTexutre = Window.loadTexture("../Res/gfx/Walk_PC.png");
    SDL_Texture *Enemy_IdleTexture = Window.loadTexture("../Res/gfx/Idle_Enemy.png");
    SDL_Texture *Enemy_WalkTexture = Window.loadTexture("../Res/gfx/Walk_Enemy.png");
    SDL_Texture *SkyboxTexture = Window.loadTexture("../Res/gfx/sky.png");
    //==================================== Render ground (aka platform)===============================
    Entity ground[] = {
        Entity(0, 0, 800, 600, grassTexture),
        Entity(32, 0, 800, 600, grassTexture),
        Entity(100, 300, 800, 600, grassTexture),
    };
    Entity skyBox = {0, 0, 656, 518, SkyboxTexture};
    Char npc = Char(30, 2, 32, 32, PC_IdleTexutre);
    // PC PlayerChar = PC(100, 400, 32, 32, PC_IdleTexutre);
    Char testCol = Char(12, 64, 64, 200, 200, PC_WalkTexutre);
    // cout << testCol << endl;
    PC PlayerChar = PC(25, 128, 128, 60, 50, 32, 32);
    NPC Npc = NPC(12, 128, 128, 360, 200, 32, 32);
    // Text Txt_score = Text("../Res/dev/font/font.ttf", "Score: placeHolder", 350, 10, 200, 200);
    Text Txt_score = Text("../Res/dev/font/font.ttf", "Score: placeHolder", 350, 10);

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
        SDL_Texture *curTex = PC_IdleTexutre;
        if (xDir != 0)
        {
            curTex = PC_WalkTexutre;
            Txt_score.refresh();
            Txt_score.Update("1234");
            // Txt_score.Update("FrameTime " + (string)frameTime);
        }
        PlayerChar.handleInput(xDir, yDir, bDash, PC_IdleTexutre, PC_WalkTexutre);

        if (animDelay > SDL_GetTicks() - frameStart)
        {
            SDL_Delay(animDelay - (SDL_GetTicks() - frameStart));
            npc.LoadAnimation(curTex);
            PlayerChar.LoadAnimation(PlayerChar.GetTexture());
            Npc.LoadAnimation(Npc.GetTexture());
        }
        // DETECT COL &  ANIMATION
        cout << PlayerChar.detectCollision(PlayerChar.getColBox(), testCol.getColBox()) << endl;
        Npc.checkDistance(PlayerChar.getColBox());
        Npc.Behavior(Enemy_IdleTexture, Enemy_WalkTexture, grassTexture);
        Npc.detectCollision(Npc.getColBox(), PlayerChar.getColBox());
        PlayerChar.Loop();
        testCol.Loop();
        // RENDER
        Window.Render(Npc, Npc.getColBox()->w, Npc.getBFlip());
        Window.Render(testCol, testCol.getColBox()->w);
        // cout << PlayerChar.getX() << "  " << PlayerChar.getY() << endl;
        Window.Render(Window.Surface2Texture(Txt_score.getSurface()), Txt_score.getRect());
        // Window.Render(PlayerChar, 64 * 2, PlayerChar.getBFlip());
        Window.Render(PlayerChar, PlayerChar.getColBox()->w, PlayerChar.getBFlip());

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
