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

class Entity
{
public:
    // SDL_Texture* texture;
    bool isAlive;
    int currHealth, maxHealth;

    virtual void renderEntity(SDL_Renderer*& entityRender, SDL_Rect* entityRect, EntityRGBA eRGBA);
    virtual void updateEntity(SDL_Renderer* entityRender, SDL_Rect* entityRect);
    Entity() {};

    // Entity(int x, int y, int w, int h)
    // {
        
    // }

    ~Entity() {}
}; 


class Healthbar : public Entity
{
public:
    void updateHealth(int maxHealth, int currHealth);

    ~Healthbar() {}
};

// class Player : public Entity
// {
// private:
//     Healthbar hb;
// public:

//     Player(int maxHealth) {};

//     ~Player();
// };

class Enemy : public Entity
{
private:
    Healthbar hb;
};

class Boss : public Entity
{
private:
    Healthbar hb;
};


#endif