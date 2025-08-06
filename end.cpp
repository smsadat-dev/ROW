#include "ROW.hpp"

void ROWMAIN::end()
{
    if(buffer)
    {
        SDL_FreeSurface(buffer);
    }

    if(texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
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