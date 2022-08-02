#include <iostream>
#include <sstream>
#include <iomanip>
#include "./include/SDL2/SDL.h"
#include "./include/renderWindow.h"
#include "./include/Entity.h"
#include "./include/SDL2/SDL_image.h"
#include "./include/SDL2/SDL_mixer.h"
#include "./include/misc.h"
#include "./include/Char.h"
#include "./include/PC.h"
#include "./include/Text.h"
#include "./include/NPC.h"
#include "./include/Enemy.h"
#include "./include/audioPlayer.h"
#include "./include/Bullet.h"
#include <random>
#include <time.h>
#include <vector>
using namespace std;

SDL_Event event;

// const int WIDTH = 800, HEIGHT = 600;
const int WIDTH = 800, HEIGHT = 800;

const int FPS = 60;
const int frameDelay = 1000 / FPS;
const int animDelay = 1000 / 10;
vector<NPC *> ActiveList;    // PC/NPC;
vector<Char *> StaticList;   // Wall, box,...;
vector<Bullet *> Bullets;    // Wall, box,...;
vector<Bullet *> BulletPool; // Wall, box,...;
Uint32 frameStart;
int frameTime;
double SCORE = 0;
bool bGameOver = false;
int main(int argc, char *argv[])
{
    /*===================== MUSIC =====================*/
    AudioPlayer mixer = AudioPlayer("../Res/audio/test.ogg");
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
    Char testCol = Char(12, 64, 64, 100, 200, BoxTexture);
    StaticList.push_back(&testCol);

    PC PlayerChar = PC(30, 60, 60, 60, 50, 32, 32);

    NPC frog1 = NPC(5, 16, 16, 360, 200, 32, 32);
    ActiveList.push_back(&frog1);
    NPC frog2 = NPC(5, 16, 16, 360, 200, 32, 32);
    ActiveList.push_back(&frog2);
    NPC frog3 = NPC(3, 32, 32, 400, 400, 32, 32);
    ActiveList.push_back(&frog3);
    NPC frog4 = NPC(3, 16, 16, 400, 0, 32, 32);
    ActiveList.push_back(&frog4);
    NPC frog5 = NPC(3, 20, 20, 0, 400, 32, 32);
    ActiveList.push_back(&frog5);

    NPC Enemy1 = NPC(20, 64, 64, 365, 100, 32, 32, true);
    ActiveList.push_back(&Enemy1);

    // Bullet bullet1 = Bullet(10, 16, 16, 0, 0, 32, 32);
    Bullet bullet1 = Bullet(10, 50, 50000, 0, 0, 32, 32);
    BulletPool.push_back(&bullet1);
    Bullet *tmp;
    Text Txt_score = Text("../Res/dev/font/font.ttf", "Score: 0.00", 350, 10);
    Text Txt_Timer = Text("../Res/dev/font/font.ttf", "Timer: 0.00", 200, 10);
    Text Txt_GameOVER = Text("../Res/dev/font/font.ttf", "GameOver: Play Again ?", 300, 300);
    stringstream stream;
    string scoreDisplay;
    /*================================== SDL LOOP==============================================*/

    bool bGameRunning = true;
    int xDir = 0, yDir = 0;
    bool bLClick = false;
    bool bDash, bshowLog, bGetInput = false;
    bshowLog = false;
    mixer.Play();
    Vector2 mousePos = Vector2(0, 0);

    while (bGameRunning)
    {

        frameStart = SDL_GetTicks();
        // EventHandler(event, bGameRunning, xDir, yDir, bDash, bGetInput, bshowLog);
        EventHandler(event, bGameRunning, xDir, yDir, bDash, bGetInput, bshowLog, bLClick, &mousePos);
        if (bGameOver)
        {
            Window.Clear();
            Txt_GameOVER.Update();
            Window.Render(skyBox, 800);
            SCORE = 0;
            mixer.Pause();
            // mixer.Stop();
            Window.Render(Window.Surface2Texture(Txt_GameOVER.getSurface()), Txt_GameOVER.getRect());
            Window.Display();
            if (bDash == true)
            {
                mixer.loadChunk("../Res/audio/scratch.wav");

                bGameOver = false;
            }
        }
        else
        {
            mixer.Resume();
            Window.Clear();
            Window.Render(skyBox, 800);
            Txt_score.Update();
            Txt_Timer.refresh();
            stringstream ss;
            ss << frameStart;
            Txt_Timer.Update("Time: " + ss.str().substr(0, 2));
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
                        if (StaticList[cj]->bgetBbullet())
                        {
                            StaticList[cj]->Loop();
                        }
                        if (ActiveList[cj] != nullptr)
                        {
                            ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), ActiveList[cj]->getColBox());
                        }
                    }
                    ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), StaticList[cj]->getColBox());
                    if (ActiveList[ci]->getBcollided())
                    {
                        // break;
                        goto toNextActive;
                    }
                    cj++;
                }
                if (ci != 0)
                    ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), ActiveList[ci - 1]->getColBox());
                PlayerChar.detectCollision(PlayerChar.getColBox(), ActiveList[ci]->getColBox());

                switch (PlayerChar.checkHit(ActiveList[ci]->getBHostile()))
                {
                case 1:
                    // bGameRunning = false;
                    std::cout << "collided with hostile" << std::endl;
                    mixer.loadChunk("../Res/audio/medium.wav");
                    mixer.PlayChunk();
                    bGameOver = true;
                    PlayerChar.setPos(ActiveList[ci]->getX() + 200, ActiveList[ci]->getY() + 800);
                    break;
                case 2:
                    // Frog get eaten
                    std::cout << "collided with frog" << std::endl;
                    srand(time(NULL));
                    mixer.loadChunk("../Res/audio/scratch.wav");
                    mixer.PlayChunk();
                    ActiveList[ci]->setPos(rand() % 900, rand() % 300);
                    SCORE += 10;
                    Txt_score.refresh();
                    stream.str("");
                    stream << fixed << setprecision(2) << SCORE;
                    scoreDisplay = "Score: " + stream.str();
                    Txt_score.Update(scoreDisplay);
                    break;
                default:
                    break;
                }
            toNextActive:
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
                ci = 0;
                for (auto i = Bullets.begin(); i != Bullets.end(); ++i)
                {
                    Bullets[ci]->LoadAnimation(Bullets[ci]->GetTexture());
                    ci++;
                }
            }
            if (bLClick)
            {
                cout << endl
                     << "CLICK" << endl;
                if (BulletPool.size() > 0 && BulletPool.size() <= 2)
                {
                    // tmp = BulletPool.back();
                    // tmp->Call(&mousePos, PlayerChar.getPos());
                    // BulletPool.pop_back();
                    // Bullets.push_back(tmp);
                    if (Bullets.size() > 0)
                        Bullets.pop_back();
                    Bullets.push_back(&bullet1);
                    Bullets.back()->Call(&mousePos, PlayerChar.getPos());
                }
            }
            ci = 0;
            for (auto i = ActiveList.begin(); i != ActiveList.end(); ++i)
            {
                int cj = 0;
                for (auto j = Bullets.begin(); j != Bullets.end(); ++j)
                {
                    Bullets[cj]->Behavior(grassTexture);
                    Bullets[cj]->checkInRange(Bullets[cj]->getColBox());
                    Bullets[cj]->Loop();
                    if (ci == 0)
                        Window.Render(*Bullets[cj], Bullets[cj]->getColBox()->w);
                    if (ActiveList[ci]->detectCollision(ActiveList[ci]->getColBox(), Bullets[cj]->getColBox()))
                    {
                        cout << "ACTIVE GET SHOT!!!";
                        Bullets.pop_back();
                        goto getShot;
                    }
                    else
                    {
                        goto notGetShot;
                    }
                    cj++;
                }
            getShot:
                ActiveList[ci]->LoopGetHit();
            notGetShot:
                ci++;
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
    Bullets.clear();
    BulletPool.clear();
    ActiveList.clear();
    StaticList.clear();
    mixer.close();
    Txt_score.clean();
    Txt_Timer.clean();
    Window.cleanUp();
    SDL_Quit();
    return 0;
}
