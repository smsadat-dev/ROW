#ifndef ROW_HPP
#define ROW_HPP

// ===== C++ =====
#include <iostream>


// ===== SDL ======
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


// ROW 

#define ROW "Rouges of Waziristan"

// ROW = Rouges of Waziristan

// class containing all necessarry fields to initiate the game


class ROWMAIN
{
private:
    SDL_Event e;
    SDL_Rect rect;

    SDL_Surface* buffer;
    Mix_Music* music;
    Mix_Chunk* sound;

    bool loadImage(SDL_Surface*& buffer, std::string imgFile);
    bool loadMusic(Mix_Music*& music, std::string musFile);
    bool loadSound(Mix_Chunk*& sound, std::string sndFile);

public:
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    bool init();
    bool initSDL_image(IMG_InitFlags imgInitflag);
    bool initSDL_mixer(int fq, Uint16 fmt, int channel, int chunksize);

    bool run();
    void end();
};

typedef enum 
{
    SDL,
    IMG,
    AUD,
    TXT,
}ROWtypes;


void ROWerror(std::string errMesg, ROWtypes t);


#endif