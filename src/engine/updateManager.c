#include "updateManager.h"
#include "gameObject.h"

updateManager* create_updateMgr(){
    updateManager* updateMgr = (updateManager*)malloc(sizeof(updateManager));
    updateMgr->elements = new_list();
    return updateMgr;
}

void add_element_updatable(updateManager* updateMgr, void* elem){
    list_add(updateMgr->elements, elem);
}
void update_elements(updateManager* updateMgr, float time_deltaTime){
    for (int i = 1; i <= updateMgr->elements->count; i++)
    {
        gameObject*go = list_elem_at(updateMgr->elements, i);
        go->update(go, time_deltaTime);
    }
}

void destroy_updateMgr(updateManager* updateMgr){
    free(updateMgr);
}