#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "sprite.h"

sprite* newSprite(SDL_Renderer* renderer, SDL_Surface* bmp_surface){
    sprite* spr = (sprite*)malloc(sizeof(sprite));

    if (bmp_surface == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not load image: %s", SDL_GetError());
    }

    spr->width = bmp_surface->w;
    spr->height = bmp_surface->h;

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


    SDL_RenderCopy(renderer, _sprite->bmp_texture, NULL, &bmp_rect);
}


