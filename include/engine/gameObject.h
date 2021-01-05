#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SDL.h>

struct gameObject
{
    float position_x;
    float position_y;
    float speed_x;
    float speed_y;
};
typedef struct gameObject gameObject;

gameObject* new_gameObject();
void destroy_gameObject(gameObject* go);

#endif /* GAME_OBJECT_H */