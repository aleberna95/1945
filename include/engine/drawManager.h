#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H
#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "list.h"

typedef struct
{
    list *gameObjs0;
    list *gameObjs1;
    list *gameObjs2;
    list *gameObjs3;
} drawManager;

drawManager *newDrawManager();
void add_render_element(drawManager* drwManager, void* go);
void draw_elements(SDL_Renderer *renderer, drawManager *drwMgr);
void change(void* a, void* b);

#endif