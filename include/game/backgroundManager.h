#ifndef BACKGROUND_MANAGER_H
#define BACKGROUND_MANAGER_H

#include "drawManager.h"
#include "updateManager.h"
#include "gameObject.h"
#include "sprite.h"
#include "list.h"
#include "component.h"

typedef struct 
{
    drawManager* drawMgr;
    updateManager* updateMgr;
    list* islands;
    float counter;
    float counterDefault;
    float backgroundSpeed;
}backgroundManager;

backgroundManager* bg_manager_init(SDL_Renderer*, updateManager*, drawManager*, float bgSpeed);
void bgMovement(void* comp, float time_deltatime);
void repositionBg(void *comp, float time_deltatime);
void spawn_island(backgroundManager *bgMgr, float time_deltatime);
void islandDeath(void *comp, float time_deltatime);

#endif