#include "ROW.hpp"

bool ROWMAIN::initSDL_ttf()
{
    if(TTF_Init() < 0)
    {
        ROWerror("Error initializing SDL_mixer:", TXT);
        return false;
    }
    return true;
}

bool ROWMAIN::loadFont(TTF_Font*& font, std::string fontFile, int ptsSize)
{
    font = TTF_OpenFont(fontFile.c_str(), ptsSize);
    if(!font)
    {
        ROWerror("Error loading font " + fontFile + " :", TXT);
        return false;
    }
    return true;
}