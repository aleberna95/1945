#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "list.h"
#include "common.h"
#include "dict.h"

#include "game.h"
#include "gameObject.h"
#include "sprite.h"
#include "drawManager.h"
#include "updateManager.h"
#include "simpleMovement_comp.h"
#include "enemyManager.h"
#include "backgroundManager.h"
#include "component.h"

int start_game(int w, int h)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "First SDL2 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        w,
        h,
        0);

    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create renderer: %s\n", SDL_GetError());
        return 2;
    }

    Uint64 curr_count = SDL_GetPerformanceCounter();
    Uint64 last_count = curr_count;
    float delta_time = 0.f;

    char title[100];
    float update_time = 0.f;
    float time_counter = 0.f;

    //init manager
    drawManager *drawMgr = newDrawManager();
    graphicsManager *graphMgr = NewGraphicManager();
    updateManager *updateMgr = create_updateMgr();

    //INIT ACTORS

    //player
    sprite *playerSprite = newSprite(renderer, 0, "resources/player/myplane_strip3.png", 59, 43, 3, 13);
    gameObject *player = new_gameObject(updateMgr, drawMgr, playerSprite, playerSprite->sprite_width, playerSprite->sprite_height, 300, 200);
    simpleMovement_comp *playerInput = simpleMovement(player, 250.f);
    component *animator = newComponent();
    animator->data->owner = player;
    animator->data->animation_duration = 0.2f;
    animator->data->num_of_sprites = 3;
    animator->data->counter = 0;
    animator->data->index = 0;
    animator->data->pixel_offset = 3;
    animator->update = spriteChanger;

    list_add(player->components, animator);

    //enemy
    enemyManager *enemyMgr = enemyManager_init(renderer, updateMgr, drawMgr, 1.5f, 640, 100.f, 20.f);

    //background
    backgroundManager *bgMgr = bg_manager_init(renderer, updateMgr, drawMgr, 40.f);

    boolean done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                done = true;
                break;
            }
        }

        last_count = curr_count;
        curr_count = SDL_GetPerformanceCounter();
        delta_time = (float)(curr_count - last_count) / (float)SDL_GetPerformanceFrequency();
        int fps = (int)(1.f / delta_time);

        update_time += delta_time;
        if (update_time >= 1.f)
        {
            update_time -= 1.f;
            sprintf_s(title, sizeof(title), "Delta Time: %.6f - Fps: %d", delta_time, fps);
            SDL_SetWindowTitle(window, title);
        }

        // Clear
        SDL_RenderClear(renderer);

        //input
        inputSystem(playerInput, delta_time);

        spawn_enemy(enemyMgr, delta_time);
        spawn_island(bgMgr, delta_time);

        //update
        update_elements(updateMgr, delta_time);

        //draw
        draw_elements(renderer, drawMgr);

        // Blit
        SDL_RenderPresent(renderer);
    }

    //Clean Up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void spriteChanger(void *comp, float delta_time)
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