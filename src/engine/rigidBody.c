#include "rigidBody.h"
#include <stdlib.h>
rigidBody *initRb(float radius, int x, int y)
{
    rigidBody *rb = (rigidBody *)malloc(sizeof(rigidBody));
    rb->radius = radius;
    rb->x = x;
    rb->y = y;
    rb->speed_x = 0;
    rb->speed_y = 0;
    rb->isActive = true;
    return rb;
}
