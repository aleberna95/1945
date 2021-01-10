#include "drawManager.h"
#include "gameObject.h"

drawManager *newDrawManager()
{
    drawManager *drwMgr = malloc(sizeof(drawManager));
    drwMgr->gameObjs = new_list();
    return drwMgr;
}

void add_render_element(drawManager *drwManager, void *go)
{
    list_add(drwManager->gameObjs, (gameObject*) go);
}

void draw_elements(SDL_Renderer *renderer, drawManager *drwMgr)
{
    for (uint i = 1; i <= drwMgr->gameObjs->count; i++)
    {
        gameObject *go = list_elem_at(drwMgr->gameObjs, i);
        if (go->isActive)
        {
            drawSprite(renderer, go->sprite);
        }
    }
}