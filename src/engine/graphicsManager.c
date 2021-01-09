#include "graphicsManager.h"

graphicsManager* NewGraphicManager(){
    graphicsManager* graphMgr = malloc(sizeof(graphicsManager));
    graphMgr->textures = new_dict();
    return graphMgr;
}
void DestroyGraphicManager(graphicsManager* graphMgr){
    free(graphMgr);
}

sprite* GetTexture(dict* dict, void* key){
    uint keylen = sizeof(key);
    return (sprite* )(dict_elem_at_key(dict, key, keylen));
}
