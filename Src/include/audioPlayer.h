#pragma once
#include "./SDL2/SDL_mixer.h"
#include <iostream>
#include <string.h>
using namespace std;

class AudioPlayer
{
public:
    AudioPlayer(string _path);
    void loadChunk(string _path);
    void Pause();
    void Stop();
    void Play();
    void close();
    void Resume();
    void PlayChunk();

private:
    Mix_Music *gmusic = NULL;
    Mix_Chunk *pSong = NULL;
};