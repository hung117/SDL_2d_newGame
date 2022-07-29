#include "../include/audioPlayer.h"
using namespace std;
AudioPlayer::AudioPlayer(string _path)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }
    gmusic = Mix_LoadMUS(_path.c_str());
    // gmusic = Mix_LoadMUS("../Res/audio/beat.wav");
    gmusic = Mix_LoadMUS("C:/Users/BDHung/Desktop/C_Document/Uni_Misc/Current/LTNC/BTL/Game/SDL_2d_newGame/Res/audio/test.ogg");
    // gmusic = Mix_LoadMUS("C:/Users/BDHung/Desktop/C_Document/Uni_Misc/Current/LTNC/BTL/Game/SDL_2d_newGame/Res/audio/AmanWOLove.mp3");
    printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
    if (gmusic == NULL)
    {
        printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
    }
}
void AudioPlayer::Resume()
{
    Mix_ResumeMusic();
}
void AudioPlayer::loadChunk(string _path)
{
    // if (_path == "")
    // {
    //     pSong = NULL;
    //     return;
    // }
    pSong = Mix_LoadWAV(_path.c_str());
    if (pSong == NULL)
    {
        cout << "Failed to load audio" << endl;
    }
}
void AudioPlayer::close()
{
    Mix_FreeChunk(pSong);
    pSong = NULL;
    Mix_FreeMusic(gmusic);
    gmusic = NULL;
}
void AudioPlayer::Pause()
{
    Mix_PauseMusic();
}
void AudioPlayer::Stop()
{
    Mix_HaltMusic();
}
void AudioPlayer::Play()
{
    Mix_PlayMusic(gmusic, -1);
}
void AudioPlayer::PlayChunk()
{
    if (pSong != NULL)
    {
        Mix_PlayChannel(-1, pSong, 0);
    }
}