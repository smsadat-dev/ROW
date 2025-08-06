#include "ROW.hpp"

bool ROWMAIN::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {

        ROWerror("Error initiating SDL:", SDL);
        return false;
    }

    if(!initSDL_image(IMG_INIT_PNG))
        return false;

    if(!initSDL_mixer(44100, MIX_DEFAULT_FORMAT, 2, 1024))
        return false;

    win = SDL_CreateWindow(ROW, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 600, 0);
    if(!win)
    {
        ROWerror("Error creating window:", SDL);
        return false;
    }

    renderer = SDL_CreateRenderer(win, -1, 0);
    if(!renderer)
    {
        ROWerror("Error creating renderer:", SDL);
        return false;
    }

    if(!loadImage(buffer, "res/cyberpunk.bmp"))
        return false;

    // make texture without image
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 1024, 1024);
    if(!texture)
    {
        ROWerror("Error creating texture for \"res/car.bmp\":", SDL);
        return false;
    }

    if(!loadMusic(music, "res/HOME-Resonance.wav"))
        return false;

    if(!loadSound(sound, "res/metal pipe.wav"))
        return false;

    unsigned char* pixels;
    int pitch;
    int textureW, textureH, access;
    unsigned int textureFmt;

    Mix_PlayMusic(music, -1);

    // get texture info
    // SDL_QueryTexture(texture, &textureFmt, &access, &textureW, &textureH);

    // SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch);

    // set pixels to solid white

    // for(int i = 0; i < pitch * textureH; i++)
    // {
    //     pixels[i] = 255;
    // }

    // SDL_UnlockTexture(texture);

    // SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    // SDL_RenderClear(renderer);
    return true;
}