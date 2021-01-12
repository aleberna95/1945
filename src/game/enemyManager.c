#include "enemyManager.h"
#include <stdlib.h>

enemyManager *enemyManager_init(SDL_Renderer *renderer, updateManager *updateMgr, drawManager *drawMgr, float spawn_counter, float width, float enemySpeed, float shootSpeed)
{
    enemyManager *enemyMgr = (enemyManager *)malloc(sizeof(enemyManager));
    enemyMgr->updateMgr = updateMgr;
    enemyMgr->drawMgr = drawMgr;
    enemyMgr->counterDefault = spawn_counter;
    enemyMgr->counter = 0;
    enemyMgr->width_spawn_max = width;
    enemyMgr->enemySpeed = enemySpeed;
    enemyMgr->shootSpeed = shootSpeed;
    // enemyMgr->active_enemies = createQueue();
    // enemyMgr->deactive_enemies = createQueue();
    // enemyMgr->bullets = createQueue();
    enemyMgr->enemies = new_list();

    for (uint i = 0; i < 15; i++)
    {
        //enemy
        sprite *enemySTDSprite = newSprite(renderer, 1, "resources/enemy/enemy1_strip3.png", 32, 31, 0, 1);
        gameObject *enemy = new_gameObject(updateMgr, drawMgr, enemySTDSprite, 32, 31, 0, 0);
        enemy->isActive = false;
        enemy->rb->isActive = false;
        enemy->rb->speed_y = enemyMgr->enemySpeed;
        enemy->rb->speed_x = 0;

        component *movement = newComponent();
        movement->data->owner = enemy;
        movement->data->self = movement;
        movement->update = enemyMovement;
        list_add(enemy->components, movement);

        component *death = newComponent();
        death->data->owner = enemy;
        death->data->self = death;
        death->update = enemyDeath;
        list_add(enemy->components, death);

        component *animator = newComponent();
        animator->data->owner = enemy;
        animator->data->animation_duration = 0.2f;
        animator->data->num_of_sprites = 3;
        animator->data->counter = 0;
        animator->data->index = 0;
        animator->data->pixel_offset = 0;
        animator->update = enemySpriteChanger;
        list_add(enemy->components, animator);

        list_add(enemyMgr->enemies, enemy);
    }

    return enemyMgr;
}
void spawn_enemy(enemyManager *enemyMgr, float time_deltatime)
{
    enemyMgr->counter += time_deltatime;
    if (enemyMgr->counter >= enemyMgr->counterDefault)
    {
        if (enemyMgr->enemies->count > 0)
        {
            enemyMgr->counter = 0;

            gameObject *go;
            for (uint i = 1; i < enemyMgr->enemies->count; i++)
            {
                go = list_elem_at(enemyMgr->enemies, i);
                if (!go->isActive)
                {
                    go->isActive = true;
                    go->rb->isActive = true;
                    go->rb->x = 50 + rand() % enemyMgr->width_spawn_max - 50;
                    go->rb->y = -15;
                    go->rb->speed_y = enemyMgr->enemySpeed;

                    break;
                }
            }
        }
    }
}
void enemyDeath(void *comp, float time_deltatime)
{
    gameObject *go = ((component *)comp)->data->owner;
    if (go->position_y > 480)
    {
        go->isActive = false;
        go->position_y = 0;
    }
}

void enemyMovement(void *comp, float time_deltatime)
{
    gameObject *go = ((component *)comp)->data->owner;
    go->rb->y += go->rb->speed_y * time_deltatime;
}

void enemySpriteChanger(void *comp, float delta_time)
{
    component *_comp = (component *)comp;

    _comp->data->counter += delta_time;
    if (_comp->data->counter >= _comp->data->animation_duration)
    {
        _comp->data->counter = 0;
        sprite *sprite = ((gameObject *)((component *)(comp))->data->owner)->sprite;
        _comp->data->index++;
        if (_comp->data->index >= _comp->data->num_of_sprites)
        {
        _comp->data->index = 0;
        }

        sprite->x_sprite_offset = _comp->data->pixel_offset + ((_comp->data->pixel_offset*2) + sprite->sprite_width) * _comp->data->index;
    }
}
// void shoot(){

// }
// void restoreBullet(){

// }
