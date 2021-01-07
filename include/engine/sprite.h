#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

struct sprite
{
     SDL_Texture *bmp_texture;
     float width;
     float height;
     float x_pivot;
     float y_pivot;
};
typedef struct sprite sprite;

sprite* newSprite(SDL_Renderer* renderer, SDL_Surface* bmp_surface);
void drawSprite(SDL_Renderer *renderer, sprite* _sprite);

#endif