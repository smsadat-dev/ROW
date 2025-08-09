#include "../ROW.hpp"

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

bool ROWMAIN::renderText(SDL_Texture*& tTexture, SDL_Surface*& textSurf, TTF_Font*& font, std::string& text)
{
    textSurf = TTF_RenderText_Solid(font, text.c_str(), {255, 0, 0, 250});
    if (!textSurf) 
    {
	    std::cout << "Failed to render text: " << TTF_GetError() << '\n';
        return false;
    }

    tTexture = SDL_CreateTextureFromSurface(renderer, textSurf);

    textDest = {10, 10, textSurf->w, textSurf->h};
   
    SDL_RenderCopy(renderer, tTexture, nullptr, &textDest);

    return true;
}