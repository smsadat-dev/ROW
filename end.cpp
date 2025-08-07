#include "ROW.hpp"

void ROWMAIN::kill()
{
    if(font)
    {
        SDL_StopTextInput();
        TTF_CloseFont(font);
        font = nullptr;
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

    TTF_Quit();
    IMG_Quit();
	Mix_Quit();
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
    SDL_QuitSubSystem(SDL_INIT_TIMER);
    SDL_Quit();
}