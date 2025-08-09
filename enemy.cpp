#include "entity.hpp"

void Enemy::renderEnemy(SDL_Renderer*& renderer,  EntityRGBA eRGBA)
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

    if(SDL_RenderFillRect(renderer, &enemyRect) < 0)
    {
        ROWerror("Error while drawing player", SDL);
        return;
    }
    std::cout << "Entity(Enemy) rendered\n";
}

void Enemy::updateEnemy()
{
    enemyRect.x += 10;
    enemyRect.y += 2;
}