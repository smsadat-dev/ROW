#include "ROW.hpp"

bool ROWMAIN::initSDL_image(IMG_InitFlags imgInitflag)
{
    if(IMG_Init(imgInitflag) < 0)
    {
        ROWerror("Error initializing SDL_image:", IMG);
        return false;
    }
    return true;
}

bool ROWMAIN::loadImage(SDL_Surface*& buffer, std::string imgFile)
{
    buffer = IMG_Load(imgFile.c_str());
    if(!buffer)
    {
        ROWerror("Error loading image " + imgFile + " :", IMG);
        return false;
    }
    return true;
}