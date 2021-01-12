#ifndef SHOOT_MANAGER_H
#define SHOOT_MANAGER_H
#include "gameObject.h"

typedef struct 
{
    gameObject* owner;
    gameObject* self;
}bullet;

bullet* newBullet(gameObject* self, gameObject* owner); 
#endif