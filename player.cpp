#include "entity.hpp"

void Player::renderPlayer(SDL_Renderer*& renderer, SDL_Rect* rect,  EntityRGBA eRGBA)
{   
    if(!renderer)
    {
        ROWerror("Error renderer unallocated for player", SDL);
        return;
    }

    if(SDL_SetRenderDrawColor(renderer, eRGBA.r, eRGBA.g, eRGBA.b, eRGBA.a) < 0)
    {
        ROWerror("Error while setting color for player", SDL);
        return;
    }

    if(SDL_RenderFillRect(renderer, rect) < 0)
    {
        ROWerror("Error while drawing player", SDL);
        return;
    }
    std::cout << "Entity(Player) rendered\n";
}