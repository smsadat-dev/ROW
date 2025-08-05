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

    SDL_FillRect(winSurf, nullptr, SDL_MapRGB(winSurf->format, 255, 90, 120));
    SDL_UpdateWindowSurface(win);

    SDL_DestroyWindow(win);
    win = nullptr;
    winSurf = nullptr; 

    SDL_Quit();
    return 0;
}
