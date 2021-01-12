#include "backgroundManager.h"
#include <string.h>

backgroundManager *bg_manager_init(SDL_Renderer *renderer, updateManager *updateMgr, drawManager *drawMgr, float bgSpeed)
{
    backgroundManager *bgMgr = (backgroundManager *)malloc(sizeof(backgroundManager));
    bgMgr->updateMgr = updateMgr;
    bgMgr->drawMgr = drawMgr;
    bgMgr->backgroundSpeed = bgSpeed;
    bgMgr->counter = 0;

    // BG1
    sprite *bgSprite = newSprite(renderer, 3, "resources/map/goodWater.png", 640, 480, 0, 0);
    gameObject *bg = new_gameObject(updateMgr, drawMgr, bgSprite, 640, 480, 320, 240);
    bg->rb->speed_y = bgMgr->backgroundSpeed;

    component *movement = newComponent();
    movement->data->owner = bg;
    movement->data->self = movement;
    movement->update = bgMovement;
    list_add(bg->components, movement);

    component *reposition = newComponent();
    reposition->data->owner = bg;
    reposition->data->self = reposition;
    reposition->update = repositionBg;
    list_add(bg->components, reposition);
    //END BG1

    //BG2
    sprite *bgSprite1 = newSprite(renderer, 3, "resources/map/goodWater.png", 640, 480, 0, 0);
    gameObject *bg1 = new_gameObject(updateMgr, drawMgr, bgSprite1, 640, 480, 320, -240);
    bg1->rb->speed_y = bgMgr->backgroundSpeed;

    component *movement1 = newComponent();
    movement1->data->owner = bg1;
    movement1->data->self = movement1;
    movement1->update = bgMovement;
    list_add(bg1->components, movement1);

    component *reposition1 = newComponent();
    reposition1->data->owner = bg1;
    reposition1->data->self = reposition1;
    reposition1->update = repositionBg;
    list_add(bg1->components, reposition1);
    //END BG2

    //ISLANDS
    bgMgr->islands = new_list();
    bgMgr->counterDefault = 1 + rand() % 5;
    for (uint i = 0; i < 15; i++)
    {
        sprite *islandSTDSprite;
        //island
        if (i % 5 == 0)
        {
            islandSTDSprite = newSprite(renderer, 2, "resources/map/island3.png", 37, 33, 5, 7);
        }
        else if (i % 2 == 0)
        {
            islandSTDSprite = newSprite(renderer, 2, "resources/map/island2.png", 62, 60, 1, 1);
        }
        else
        {
            islandSTDSprite = newSprite(renderer, 2, "resources/map/island1.png", 46, 47, 2, 4);
        }

        gameObject *island = new_gameObject(updateMgr, drawMgr, islandSTDSprite, 62, 60, 0, 0);
        island->isActive = false;
        island->rb->isActive = false;
        island->rb->speed_y = bgMgr->backgroundSpeed;
        island->rb->speed_x = 0;

        component *movement = newComponent();
        movement->data->owner = island;
        movement->data->self = movement;
        movement->update = bgMovement;
        list_add(island->components, movement);

        component *death = newComponent();
        death->data->owner = island;
        death->data->self = death;
        death->update = islandDeath;
        list_add(island->components, death);

        list_add(bgMgr->islands, island);
    }

    return bgMgr;
}
void bgMovement(void *comp, float time_deltatime)
{
    gameObject *go = ((component *)comp)->data->owner;
    go->rb->y += go->rb->speed_y * time_deltatime;
}
void islandDeath(void *comp, float time_deltatime)
{
    gameObject *go = ((component *)comp)->data->owner;
    if (go->position_y > 480)
    {
        go->isActive = false;
        go->position_y = 0;
    }
}

void repositionBg(void *comp, float time_deltatime)
{
    gameObject *go = ((component *)comp)->data->owner;
    if (go->position_y > 480)
    {
        go->rb->x = 0;
        go->rb->y = -480;
    }
}

void spawn_island(backgroundManager *bgMgr, float time_deltatime)
{
    bgMgr->counter += time_deltatime;
    if (bgMgr->counter >= bgMgr->counterDefault)
    {
        if (bgMgr->islands->count > 0)
        {
            bgMgr->counterDefault = 1 + rand() % 5;
            bgMgr->counter = 0;

            gameObject *go;
            for (uint i = 1; i < bgMgr->islands->count; i++)
            {
                go = list_elem_at(bgMgr->islands, i);
                if (!go->isActive)
                {
                    go->isActive = true;
                    go->rb->isActive = true;
                    go->rb->x = 50 + rand() % 600;
                    go->rb->y = -100;
                    go->rb->speed_y = bgMgr->backgroundSpeed;

                    break;
                }
            }
        }
    }
}