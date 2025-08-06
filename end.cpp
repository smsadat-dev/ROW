#include "ROW.hpp"

void ROWMAIN::end()
{
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