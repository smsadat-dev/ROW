#include "../ROW.hpp"

void ROWerror(std::string errMesg, ROWtypes t)
{
    switch (t)
    {
    case SDL:
        std::cerr << "ROW: " << errMesg << '\n'
        << SDL_GetError() << '\n';
        break;
    case IMG:
        std::cerr << "ROW: " << errMesg << '\n'
        << IMG_GetError() << '\n';
        break;
    case AUD:
        std::cerr << "ROW: " << errMesg << '\n'
        << Mix_GetError() << '\n';
        break;
    case TXT:
        std::cerr << "ROW: " << errMesg << '\n'
        << TTF_GetError() << '\n';
        break;
    default:
        break;
    }

    
}