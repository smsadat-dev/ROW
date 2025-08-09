#include "../ROW.hpp"

bool ROWMAIN::init()
{
    if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
    {
        std::cerr << "Failed to start SDL events:" << SDL_GetError() << '\n';
    }

    if(SDL_InitSubSystem(SDL_INIT_TIMER) < 0)
    {
        std::cerr << "Failed to start SDL timer:" << SDL_GetError() << '\n';
    }

    if(SDL_WasInit(SDL_INIT_EVENTS) == SDL_INIT_EVENTS)
    {
        std::cout << "SDL events initialized\n";
    }
    if(SDL_WasInit(SDL_INIT_TIMER) == SDL_INIT_TIMER)
    {
        std::cout << "SDL timer initialized\n";
    }

    if(!initSDL_image(IMG_INIT_PNG))
        return false;

    if(!initSDL_mixer(44100, MIX_DEFAULT_FORMAT, 2, 1024))
        return false;

    if(!initSDL_ttf())
        return false;

    // for debugging purpose
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);


    win = SDL_CreateWindow(ROW, 100, 100, ROW_WINW, ROW_WINH, 0);
    if(!win)
    {
        ROWerror("Error creating window:", SDL);
        return false;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cerr << "Error rendering :" << SDL_GetError() << '\n';
    }

    if(!loadImage(buffer, "res/cyberpunk.bmp"))
        return false;

    if(!loadMusic(music, "res/HOME-Resonance.wav"))
        return false;

    if(!loadSound(sound, "res/metal pipe.wav"))
        return false;

    if(!loadFont(font, "res/chilispepper.ttf", 72))
        return false;
    
    return true;
}