#include "ROW.hpp"

bool ROWMAIN::initSDL_mixer(int fq, Uint16 fmt, int channel, int chunksize)
{
    if(Mix_OpenAudio(fq, fmt, channel, chunksize) < 0)
    {
        ROWerror("Error initializing SDL_mixer:", AUD);
        return false;
    }
    return true;
}

bool ROWMAIN::loadMusic(Mix_Music*& music, std::string musFile)
{
    music = Mix_LoadMUS(musFile.c_str());
    if(!music)
    {
        ROWerror("Error loading image " + musFile + " :", AUD);
        return false;
    }
    return true;
}

bool ROWMAIN::loadSound(Mix_Chunk*& sound, std::string sndFile)
{
    sound = Mix_LoadWAV(sndFile.c_str());
    if(!sound)
    {
        ROWerror("Error loading image " + sndFile + " :", IMG);
        return false;
    }
    return true;
}