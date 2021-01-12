#include "drawManager.h"
#include "gameObject.h"

drawManager *newDrawManager()
{
    drawManager *drwMgr = malloc(sizeof(drawManager));
    drwMgr->gameObjs0 = new_list();
    drwMgr->gameObjs1 = new_list();
    drwMgr->gameObjs2 = new_list();
    drwMgr->gameObjs3 = new_list();
    return drwMgr;
}

void add_render_element(drawManager *drwManager, void *go)
{
    int layer = ((gameObject *)(go))->sprite->layer;
    switch (layer)
    {
    case 0:
        list_add(drwManager->gameObjs0, (gameObject *)go);
        break;
    case 1:
        list_add(drwManager->gameObjs1, (gameObject *)go);
        break;
    case 2:
        list_add(drwManager->gameObjs2, (gameObject *)go);
        break;
    case 3:
        list_add(drwManager->gameObjs3, (gameObject *)go);
        break;

    default:
        break;
    }
}

void draw_elements(SDL_Renderer *renderer, drawManager *drwMgr)
{
    for (uint i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            for (uint k = 1; k <= drwMgr->gameObjs3->count; k++)
            {
                gameObject *go = list_elem_at(drwMgr->gameObjs3, k);
                if (go->isActive)
                {
                    drawSprite(renderer, go->sprite);
                }
            }
            break;

            case 1:
            for (uint k = 1; k <= drwMgr->gameObjs2->count; k++)
            {
                gameObject *go = list_elem_at(drwMgr->gameObjs2, k);
                if (go->isActive)
                {
                    drawSprite(renderer, go->sprite);
                }
            }
            break;

            case 2:
            for (uint k = 1; k <= drwMgr->gameObjs1->count; k++)
            {
                gameObject *go = list_elem_at(drwMgr->gameObjs1, k);
                if (go->isActive)
                {
                    drawSprite(renderer, go->sprite);
                }
            }
            break;

            case 3:
            for (uint k = 1; k <= drwMgr->gameObjs0->count; k++)
            {
                gameObject *go = list_elem_at(drwMgr->gameObjs0, k);
                if (go->isActive)
                {
                    drawSprite(renderer, go->sprite);
                }
            }
            break;

        default:
            break;
        }
    }
    // for (uint k = 1; k <= drwMgr->gameObjs0->count; k++)
    // {
    //     gameObject *go = list_elem_at(drwMgr->gameObjs0, k);
    //     if (go->isActive)
    //     {
    //         drawSprite(renderer, go->sprite);
    //     }
    // }
}

void change(gameObject *a, gameObject *b)
{
    gameObject temp;
    temp = *a;
    *a = *b;
    *b = temp;
}