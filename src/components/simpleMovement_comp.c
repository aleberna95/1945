#include "simpleMovement_comp.h"

simpleMovement_comp *simpleMovement(gameObject *owner, float speed)
{
    simpleMovement_comp *comp = (simpleMovement_comp *)malloc(sizeof(simpleMovement_comp));
    comp->owner = owner;
    comp->speed = speed;

    return comp;
}

void inputSystem(simpleMovement_comp *comp, float deltaTime)
{
    Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT])
    {
        comp->owner->rb->x -= comp->speed * deltaTime;
    }
    else if (state[SDL_SCANCODE_RIGHT])
    {
        comp->owner->rb->x += comp->speed * deltaTime;
    }

    if (state[SDL_SCANCODE_UP])
    {
        comp->owner->rb->y -= comp->speed * deltaTime;
    }
    else if (state[SDL_SCANCODE_DOWN])
    {
        comp->owner->rb->y += comp->speed * deltaTime;
    }

    if (state[SDL_SCANCODE_SPACE])
    {
    }
}

void autoMovement(simpleMovement_comp *comp, float deltaTime)
{
    comp->owner->rb->y += comp->speed * deltaTime;
}
