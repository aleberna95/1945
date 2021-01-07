#include "drawManager.h"
#include "gameObject.h"
#include "sprite.h"
#include "list.h"

drawManager *newDrawManager()
{
    drawManager *drwMgr = malloc(sizeof(drawManager));
    drwMgr->gameObjs = new_list();
    return drwMgr;
}

void draw_elements(SDL_Renderer *renderer, drawManager *drwMgr)
{
    for (uint i = 1; i <= drwMgr->gameObjs->count; i++)
    {
        drawSprite(renderer, (sprite *)(list_elem_at(drwMgr->gameObjs, i)));
    }
}