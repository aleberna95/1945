#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "common.h"
#include "vector.h"
#include "sprite.h"
#include "drawManager.h"
#include "updateManager.h"
#include "rigidBody.h"

typedef struct 
{
    rigidBody* rb;
    boolean isActive;
    float position_x;
    float position_y;
    float width;
    float height;
    sprite* sprite;
    void (*update)(void*, float delta_time);
}gameObject;

gameObject* new_gameObject(updateManager* updateMgr, drawManager* drawMgr, sprite* sprite, float width, float height, float pos_x, float pos_y);
void destroy_gameObject(gameObject* go);
void update(void* self, float delta_time);

#endif /* GAME_OBJECT_H */