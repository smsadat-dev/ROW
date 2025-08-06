#include "ROW.hpp"

void ROWerror(std::string errMesg)
{
    std::cerr << "ROW: " << errMesg << '\n'
    << SDL_GetError() << '\n';
}