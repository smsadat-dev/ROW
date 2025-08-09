#ifndef ROW_HPP
#define ROW_HPP

// ===== C++ =====
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ===== SDL ======
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>


// ROW 

#define ROW "Rouges of Waziristan"

#define ROW_WINW 1000
#define ROW_WINH 600

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

    TTF_Font * font; 
    SDL_Surface* text; 
    SDL_Texture* textTexture; 
    SDL_Rect textDest;
    std::string textInput;

    SDL_Surface* surface; 
    Uint16 color = 0;

    SDL_Event event;
    SDL_Scancode scode;
    SDL_Keycode kcode; 

    Uint64 start = 0;
    Uint64 end = 0;

    bool loadImage(SDL_Surface*& buffer, std::string imgFile);
    bool loadMusic(Mix_Music*& music, std::string musFile);
    bool loadSound(Mix_Chunk*& sound, std::string sndFile);
    bool loadFont(TTF_Font*& font, std::string fontFile, int ptsSize);

    bool renderText(SDL_Texture*& tTexture, SDL_Surface*& textSurf, TTF_Font*& font, std::string& text);

public:
    SDL_Window* win; 
    SDL_Renderer* renderer; 

    bool init();
    bool initSDL_image(IMG_InitFlags imgInitflag);
    bool initSDL_mixer(int fq, Uint16 fmt, int channel, int chunksize);
    bool initSDL_ttf();

    bool run();
    void kill();
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