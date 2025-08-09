#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "ROW.hpp"

struct EntityRGBA 
{
    int r;
    int g;
    int b;
    int a;
};


class Healthbar
{
public:
    void updateHealth(int maxHealth, int currHealth);

    ~Healthbar() {}
};


class Entity
{
private:
    Healthbar hb;

public:
    // SDL_Texture* texture;
    bool isAlive;
    int currHealth, maxHealth;

    ~Entity() {}
}; 


class Player : public Entity
{
public:

    void renderPlayer(SDL_Renderer*& renderer, SDL_Rect* rect,  EntityRGBA eRGBA);

    Player() {};

    ~Player() {};
};

class Enemy : public Entity
{
private:
    SDL_Rect enemyRect;

public:

    void renderEnemy(SDL_Renderer*& renderer,  EntityRGBA eRGBA);
    void updateEnemy();

    Enemy(int w, int h, int x, int y) 
    {
        enemyRect.h = h;
        enemyRect.w = w;
        enemyRect.x = x;
        enemyRect.y = y;
    };

    ~Enemy() {};
};

class Boss : public Entity
{
private:
    Healthbar hb;
};



#endif