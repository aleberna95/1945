#ifndef RIGIBODY_H
#define RIGIBODY_H

#include "common.h"

typedef struct 
{
    boolean isActive;
    float x;
    float y; 
    float radius;
    float speed_x;
    float speed_y;
}rigidBody;

void rb_update(rigidBody* rb, float deltaTime);

#endif