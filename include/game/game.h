#ifndef GAME_H
#define GAME_H
#include "graphicsManager.h"

int start_game(int w, int h);
void LoadTextures(SDL_Renderer *renderer, graphicsManager *graphMgr);
void spriteChanger(void *comp, float delta_time);
#endif
