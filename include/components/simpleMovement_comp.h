#ifndef SIMPLE_MOVEMENT_H
#define SIMPLE_MOVEMENT_H
#include "gameObject.h"
#include "shootManager.h"

typedef struct 
{
    gameObject* owner;
    float speed;
}simpleMovement_comp;


simpleMovement_comp* simpleMovement(gameObject* owner, float speed);
void inputSystem(simpleMovement_comp* comp, float deltaTime);
void autoMovement(simpleMovement_comp* comp, float deltaTime);
#endif