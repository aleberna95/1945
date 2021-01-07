#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "vector.h"
#include "sprite.h"

typedef struct 
{
    float position_x;
    float position_y;
    float width;
    float height;
    sprite* sprite;
}gameObject;

gameObject* new_gameObject(sprite* sprite, float pos_x, float pos_y);
void destroy_gameObject(gameObject* go);

#endif /* GAME_OBJECT_H */