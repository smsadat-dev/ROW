#include "ROW.hpp"

bool ROWMAIN::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        ROWerror("Error initiating SDL:");
        return false;
    }

    win = SDL_CreateWindow(ROW, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 600, 0);
    if(!win)
    {
        ROWerror("Error creating window:");
        return false;
    }

    renderer = SDL_CreateRenderer(win, -1, 0);
    if(!renderer)
    {
        ROWerror("Error creating renderer:");
        return false;
    }

    buffer = SDL_LoadBMP("res/car.bmp");
    if(!buffer)
    {
        ROWerror("Error loading image \"res/car.bmp\":");
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, buffer);
    if(!texture)
    {
        ROWerror("Error creating texture for \"res/car.bmp\":");
        return false;
    }

    // SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    // SDL_RenderClear(renderer);
    return true;
}