#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include "drawManager.h"
#include "updateManager.h"
#include "gameObject.h"
#include "sprite.h"
#include "bullet.h"
#include "list.h"
#include "component.h"

typedef struct 
{
    SDL_Renderer* renderer;
    drawManager* drawMgr;
    updateManager* updateMgr;
    list* enemies;
    float counterDefault;
    float counter;
    int width_spawn_max;
    float enemySpeed;
    float shootSpeed;
}enemyManager;

enemyManager* enemyManager_init(SDL_Renderer* renderer, updateManager* updateMgr, drawManager*, float spawn_counter, float width, float enemySpeed, float shootSpeed);
void spawn_enemy(enemyManager* enemyMgr, float time_deltatime);
void enemyMovement(void* comp, float time_deltatime);
void enemyDeath(void *comp, float time_deltatime);
void enemySpriteChanger(void *comp, float delta_time);
#endif