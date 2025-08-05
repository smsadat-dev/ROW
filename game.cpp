#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char const *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* win = SDL_CreateWindow("Rogues of Waziristan", 400, 400, 800, 600, SDL_WINDOW_SHOWN);

    if(!win)
    {
        std::cerr << "Failed to create window: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Surface* winSurf = SDL_GetWindowSurface(win);

    if(!winSurf)
    {
        std::cerr << "Failed to get window surface: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    int r = 0, g = 0, b = 0;
    while (true)
    {
        SDL_FillRect(winSurf, nullptr, SDL_MapRGB(winSurf->format, r, g, b));
        SDL_UpdateWindowSurface(win);

        r += (r+2)*3;
        g += (g+1)*2;
        b += (b+0)*1;
    }

    
    SDL_DestroyWindow(win);
    win = nullptr;
    winSurf = nullptr; 

    SDL_Quit();
    return 0;
}
