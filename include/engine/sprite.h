#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

struct sprite
{
     SDL_Texture *bmp_texture;
     int layer; //0 max prio
     float width;
     float height;
     float x_pivot;
     float y_pivot;
     float sprite_width;
     float sprite_height;
     float x_sprite_offset;
     float y_sprite_offset;
};
typedef struct sprite sprite;

sprite* newSprite(SDL_Renderer* renderer, int layer, char texturePath[], float sprite_width, float sprite_height, float x_offset, float y_offset);
void drawSprite(SDL_Renderer *renderer, sprite* _sprite);

#endif