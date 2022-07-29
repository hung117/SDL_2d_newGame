#include <iostream>
#include <sstream>
#include <iomanip>
#include "./include/SDL2/SDL.h"
#include "./include/renderWindow.h"
#include "./include/Entity.h"
#include "./include/SDL2/SDL_image.h"
#include "./include/misc.h"
#include "./include/Char.h"
#include "./include/PC.h"
#include "./include/Text.h"
#include "./include/NPC.h"
#include "./include/Enemy.h"
#include <random>
#include <time.h>
#include <vector>
using namespace std;

SDL_Event event;

const int WIDTH = 800, HEIGHT = 600;
const int FPS = 60;
const int frameDelay = 1000 / FPS;
const int animDelay = 1000 / 10;
vector<NPC *> ActiveList;  // PC/NPC;
vector<Char *> StaticList; // Wall, box,...;
Uint32 frameStart;
int frameTime;
double SCORE = 0;
bool bGameOver = false;
int main(int argc, char *argv[])
{
    /*============================================ INIT ===================================*/
    RenderWindow Window("Game v1.0", WIDTH, HEIGHT); // CPP Construction

    SDL_Texture *grassTexture = Window.loadTexture("../Res/gfx/grass.png");
    // SDL_Texture * groundTexture = Window.load
    SDL_Texture *PC_IdleTexutre = Window.loadTexture("../Res/gfx/Idle_PC.png");
    SDL_Texture *PC_WalkTexutre = Window.loadTexture("../Res/gfx/Walk_PC.png");
    SDL_Texture *Enemy_IdleTexture = Window.loadTexture("../Res/gfx/Idle_Enemy.png");
    SDL_Texture *Enemy_WalkTexture = Window.loadTexture("../Res/gfx/Walk_Enemy.png");
    SDL_Texture *Frog_HopTexture = Window.loadTexture("../Res/gfx/frog_hop.png");
    SDL_Texture *Frog_IdleTexture = Window.loadTexture("../Res/gfx/frog_Idle.png");
    // SDL_Texture *SkyboxTexture = Window.loadTexture("../Res/gfx/sky.png");
    SDL_Texture *SkyboxTexture = Window.loadTexture("../Res/gfx/ground.png");
    SDL_Texture *BoxTexture = Window.loadTexture("../Res/gfx/box.png");
    //==================================== Render ground (aka platform)===============================
    Entity ground[] = {
        Entity(0, 0, 800, 600, grassTexture),
        Entity(32, 0, 800, 600, grassTexture),
        Entity(100, 300, 800, 600, grassTexture),
    };
    Char box = Char(0, 32, 32, 300, 300, BoxTexture);
    Char box2 = Char(0, 32, 32, 550, 350, BoxTexture);
    Char box3 = Char(0, 32, 32, 100, 350, BoxTexture);
    Char box4 = Char(0, 32, 32, 600, 700, BoxTexture);
    StaticList.push_back(&box);
    StaticList.push_back(&box2);
    StaticList.push_back(&box3);
    StaticList.push_back(&box4);
    Entity skyBox = {0, 0, 656, 518, SkyboxTexture};
    Char testCol = Char(12, 64, 64, 200, 200, grassTexture);
    StaticList.push_back(&testCol);

    PC PlayerChar = PC(30, 60, 60, 60, 50, 32, 32);
    // NPC Npc = NPC(24, 64, 64, 360, 200, 32, 32);
    // ActiveList.push_back(&Npc);
    NPC frog1 = NPC(10, 16, 16, 360, 200, 32, 32);
    ActiveList.push_back(&frog1);
    NPC frog2 = NPC(10, 16, 16, 360, 200, 32, 32);
    ActiveList.push_back(&frog2);
    NPC frog3 = NPC(24, 32, 32, 400, 400, 32, 32);
    ActiveList.push_back(&frog3);
    // Enemy Enemy1 = Enemy(20, 64, 64, 365, 100, 32, 32);
    NPC Enemy1 = NPC(20, 64, 64, 365, 100, 32, 32, true);
    ActiveList.push_back(&Enemy1);

    Text Txt_score = Text("../Res/dev/font/font.ttf", "Score: 0.00", 350, 10);
    Text Txt_Timer = Text("../Res/dev/font/font.ttf", "SCORE: ", 200, 10);
    Text Txt_GameOVER = Text("../Res/dev/font/font.ttf", "GameOver: Play Again ?", 300, 300);

    /*================================== SDL LOOP==============================================*/

    bool bGameRunning = true;
    int xDir = 0, yDir = 0;
    bool bDash, bshowLog, bGetInput = false;

    while (bGameRunning)
    {
        frameStart = SDL_GetTicks();
        EventHandler(event, bGameRunning, xDir, yDir, bDash, bGetInput, bshowLog);
        if (bGameOver)
        {
            Window.Clear();
            Txt_GameOVER.Update();
            Window.Render(skyBox, 800);

            Window.Render(Window.Surface2Texture(Txt_GameOVER.getSurface()), Txt_GameOVER.getRect());
            Window.Display();
            if (bDash == true)
            {
                bGameOver = false;
                PlayerChar.setPos(0, 0);
            }
        }
        else
        {
            Window.Clear();
            Window.Render(skyBox, 800);
            Txt_score.Update();
            Txt_Timer.Update();
            for (int i = 0; i < sizeof(ground) / sizeof(ground[0]); i++)
            {
                Window.Render(ground[i], 32);
            }
            // DETECT COL
            PlayerChar.handleInput(xDir, yDir, bDash, PC_IdleTexutre, PC_WalkTexutre);
            int ci = 0; // count i;
            for (auto i = ActiveList.begin(); i != ActiveList.end(); ++i)
            {
                int cj = 0;
                ActiveList[ci]->checkDistance(PlayerChar.getColBox());
                if (ActiveList[ci]->getBHostile())
                {
                    ActiveList[ci]->Behavior(Enemy_IdleTexture, Enemy_WalkTexture, grassTexture);
                }
                else
                {
                    ActiveList[ci]->Behavior(Frog_IdleTexture, Frog_HopTexture, grassTexture);
                }
                for (auto j = StaticList.begin(); j != StaticList.end(); ++j)
                {
                    if (ci != 0)
                    {
                        if (ActiveList[cj] != nullptr)
                        {
                            ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), ActiveList[cj]->getColBox());
                        }
                    }
                    ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), StaticList[cj]->getColBox());
                    if (ActiveList[ci]->getBcollided())
                    {
                        break;
                    }
                    cj++;
                }
                if (ci != 0)
                    ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), ActiveList[ci - 1]->getColBox());
                // PlayerChar.detectCollision(PlayerChar.getColBox(), ActiveList[ci]->getColBox());
                PlayerChar.detectCollision(PlayerChar.getColBox(), ActiveList[ci]->getColBox());
                stringstream stream;
                switch (PlayerChar.checkHit(ActiveList[ci]->getBHostile()))
                {
                case 1:
                    // bGameRunning = false;
                    std::cout << "collided with hostile" << std::endl;
                    bGameOver = true;
                    break;
                case 2:
                    // Frog get eaten
                    std::cout << "collided with frog" << std::endl;
                    srand(time(NULL));
                    ActiveList[ci]->setPos(rand() % 900, rand() % 300);
                    SCORE += 10;
                    Txt_score.refresh();
                    stream << fixed << setprecision(2) << SCORE;
                    Txt_score.Update(stream.str());
                    break;
                default:
                    break;
                }
                ActiveList[ci]->Loop();
                Window.Render(PlayerChar, PlayerChar.getColBox()->w, PlayerChar.getBFlip());
                Window.Render(*ActiveList[ci], ActiveList[ci]->getColBox()->w, ActiveList[ci]->getBFlip());
                ci++;
            }
            int staticI = 0;
            for (auto i = StaticList.begin(); i != StaticList.end(); i++)
            {
                PlayerChar.detectCollision(PlayerChar.getColBox(), StaticList[staticI]->getColBox());
                if (PlayerChar.getBcollided())
                {
                    break;
                }
                staticI++;
            }

            PlayerChar.Loop();
            //  ANIMATION
            if (animDelay > SDL_GetTicks() - frameStart)
            {
                SDL_Delay(animDelay - (SDL_GetTicks() - frameStart));
                PlayerChar.LoadAnimation(PlayerChar.GetTexture());
                int ci = 0;
                for (auto i = ActiveList.begin(); i != ActiveList.end(); ++i)
                {
                    ActiveList[ci]->LoadAnimation(ActiveList[ci]->GetTexture());
                    ci++;
                }
            }

            // RENDER
            staticI = 0; // Render static:
            for (auto j = StaticList.begin(); j != StaticList.end(); ++j)
            {
                Window.Render(*StaticList[staticI], StaticList[staticI]->getColBox()->w);
                staticI++;
            }
            Window.Render(Window.Surface2Texture(Txt_score.getSurface()), Txt_score.getRect());
            Window.Render(Window.Surface2Texture(Txt_Timer.getSurface()), Txt_Timer.getRect());

            Window.Display();
            frameTime = SDL_GetTicks() - frameStart;
            if (frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
    }
    Txt_score.clean();
    Txt_Timer.clean();
    Window.cleanUp();
    SDL_Quit();
    return 0;
}
