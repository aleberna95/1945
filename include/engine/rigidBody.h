#ifndef RIGIBODY_H
#define RIGIBODY_H

#include "gameObject.h"

typedef struct 
{
    gameObject* owner;
    float x;
    float y; 
    float width;
    float height;
    float speed;
}rigidBody;

rigidBody* newRigidbody(gameObject*owner, float speed);


#endif