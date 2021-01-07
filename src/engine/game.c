#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "common.h"
#include "game.h"
#include "gameObject.h"
#include "sprite.h"
#include "list.h"
#include "drawManager.h"
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

    //test start
    drawManager* drawMgr = newDrawManager();

    SDL_Surface *bmp_surface = IMG_Load("resources/map/island1.png");
    SDL_Surface *bmp_surface2 = IMG_Load("resources/map/island2.png");
    SDL_Surface *bmp_surface3 = IMG_Load("resources/map/island2.png");

    sprite* sp = newSprite(renderer, bmp_surface);
    sprite* sp2 = newSprite(renderer, bmp_surface2);
    sprite*sp3 = newSprite(renderer, bmp_surface3);

    gameObject* go = new_gameObject(sp, 25, 25);
    gameObject* go2 = new_gameObject(sp2, 100, 100);
    gameObject* go3 = new_gameObject(sp3, 300, 300);

    list_add(drawMgr->gameObjs, go->sprite); 
    list_add(drawMgr->gameObjs, go2->sprite);
    list_add(drawMgr->gameObjs, go3->sprite);

    //test end


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

        //update

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
