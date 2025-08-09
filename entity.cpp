#include "ROW.hpp"
#include "entity.hpp"

// void Entity::updateEntity(SDL_Renderer* entityRender)
// {
//     if(SDL_RenderFillRect(entityRender, &entityRect) < 0)
//     {
//         std::cerr << "Failed to fill rectangle: " << SDL_GetError() << '\n';
//     }
//     std::cout << "Entity pos updated\n";
// }

// void Entity::renderEntity(SDL_Renderer*& entityRender, EntityRGBA eRGBA)
// {
//     if(!entityRender)
//     {
//         ROWerror("Error renderer unallocated for entity", SDL);
//         return;
//     }

//     if(SDL_SetRenderDrawColor(entityRender, eRGBA.r, eRGBA.g, eRGBA.b, eRGBA.a) < 0)
//     {
//         ROWerror("Error while setting color entity", SDL);
//         return;
//     }

//     if(SDL_RenderFillRect(entityRender, &entityRect) < 0)
//     {
//         ROWerror("Error while drawing entity", SDL);
//         return;
//     }
//     std::cout << "Entity rendered\n";
// }

void Healthbar::updateHealth(int maxHealth, int currHealth)
{

}