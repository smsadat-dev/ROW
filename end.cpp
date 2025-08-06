#include "ROW.hpp"

void ROWMAIN::end()
{
    if(texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    if(buffer)
    {
        SDL_FreeSurface(buffer);
        buffer = nullptr;
    }

    if(music)
    {
        Mix_FreeMusic(music);
        music = nullptr;
    }

    if(sound)
    {
        Mix_FreeChunk(sound);
        sound = nullptr;
    }

    if(renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if(win)
    {
        SDL_DestroyWindow(win);
        win = nullptr;
    }

    SDL_Quit();
}