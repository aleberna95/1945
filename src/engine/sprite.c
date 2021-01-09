#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "sprite.h"

sprite* newSprite(SDL_Renderer* renderer, char texturePath[], float sprite_width, float sprite_height, float x_offset, float y_offset){
    sprite* spr = (sprite*)malloc(sizeof(sprite));

    SDL_Surface *bmp_surface = IMG_Load(texturePath);
    if (bmp_surface == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not load image: %s", SDL_GetError());
    }

    spr->width = 0;
    spr->height = 0;

    spr->sprite_width = sprite_width;
    spr->sprite_height = sprite_height;
    spr->x_sprite_offset = x_offset;
    spr->y_sprite_offset = y_offset;

    //Load on GPU
    SDL_Texture *bmp_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
    spr->bmp_texture = bmp_texture;
    //Free RAM
    SDL_FreeSurface(bmp_surface);

    return spr;
}

void drawSprite(SDL_Renderer *renderer, sprite* _sprite){
    SDL_Rect bmp_rect;
    bmp_rect.x = _sprite->x_pivot;
    bmp_rect.y = _sprite->y_pivot;
    bmp_rect.w = _sprite->width;
    bmp_rect.h = _sprite->height;

    SDL_Rect sprite_rect;
    sprite_rect.x = _sprite->x_sprite_offset;
    sprite_rect.y = _sprite->y_sprite_offset;
    sprite_rect.w = _sprite->sprite_width;
    sprite_rect.h = _sprite->sprite_height;


    SDL_RenderCopy(renderer, _sprite->bmp_texture, &sprite_rect, &bmp_rect);
}


