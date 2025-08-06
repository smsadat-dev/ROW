#ifndef ROW_HPP
#define ROW_HPP

// ===== C++ =====
#include <iostream>


// ===== SDL ======
#include <SDL2/SDL.h>


// ROW 

#define ROW "Rouges of Waziristan"

// ROW = Rouges of Waziristan

// class containing all necessarry fields to initiate the game


class ROWMAIN
{
private:
    SDL_Event e;
    SDL_Rect rect;

public:
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_Surface* buffer;
    SDL_Texture* texture;

    bool init();
    bool run();
    void end();
};

void ROWerror(std::string errMesg);


#endif