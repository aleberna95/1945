#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include "sprite.h"
#include "dict.h"

typedef struct 
{
    dict* textures;
}graphicsManager;

graphicsManager* NewGraphicManager();
void DestroyGraphicManager(graphicsManager*);
sprite* GetTexture(dict* dict, void* key);


#endif