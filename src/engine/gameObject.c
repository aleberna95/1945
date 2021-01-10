#include "gameObject.h"
#include <stdlib.h>

gameObject *new_gameObject(updateManager *updateMgr, drawManager *drawMgr, sprite *_sprite, float width, float height, float pos_x, float pos_y)
{
    gameObject *go = (gameObject *)malloc(sizeof(gameObject));
    if (_sprite != NULL)
    {
        go->sprite = _sprite;
    }
    go->position_x = pos_x;
    go->position_y = pos_y;
    go->width = width;
    go->height = height;
    go->update = update;
    go->isActive = true;
    _sprite->width = width;
    _sprite->height = height;

    _sprite->x_pivot = go->position_x - _sprite->width * 0.5f;
    _sprite->y_pivot = go->position_y - _sprite->height * 0.5f;

    rigidBody *rb = (rigidBody *)malloc(sizeof(rigidBody));

    rb->radius = go->height;
    rb->x = _sprite->x_pivot;
    rb->y = _sprite->y_pivot;
    rb->isActive = true;

    go->rb = rb;

    add_render_element(drawMgr, go);
    add_element_updatable(updateMgr, go);

    return go;
}

void destroy_gameObject(gameObject *go)
{
    free(go);
}

void update(void *self, float delta_time)
{
    gameObject *go = (gameObject *)(self);
    // go->sprite->x_pivot = go->position_x - go->width*0.5f;
    // go->sprite->y_pivot = go->position_y - go->height*0.5f;
    go->sprite->x_pivot = go->rb->x;
    go->sprite->y_pivot = go->rb->y;
}