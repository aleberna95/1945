#include "gameObject.h"
#include <stdlib.h>

gameObject *new_gameObject(sprite *_sprite, float pos_x, float pos_y)
{
    gameObject *go = (gameObject *)malloc(sizeof(gameObject));
    if (_sprite != NULL)
    {
        go->sprite = _sprite;
    }
    go->position_x = pos_x;
    go->position_y = pos_y;
    go->width = _sprite->width;
    go->height = _sprite->height;

    _sprite->x_pivot = go->position_x - _sprite->width * 0.5f;
    _sprite->y_pivot = go->position_y - _sprite->height * 0.5f;

    return go;
}

void destroy_gameObject(gameObject* go){
    free(go);
}