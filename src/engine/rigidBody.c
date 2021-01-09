#include "rigidBody.h"

rigidBody* newRigidbody(gameObject*owner, float speed){
    rigidBody* rb = (rigidBody*)malloc(sizeof(rigidBody));
    rb->owner = owner;
    rb->speed = speed;
    rb->x = owner->position_x - owner->width*0.5f;
    rb->y = owner->position_y - owner->height*0.5f;
    rb->width = owner->width;
    rb->height = owner->height;

    return rb;
}
