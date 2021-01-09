#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H


#include "list.h"

    typedef struct 
    {
        list* elements;
    }updateManager;

updateManager* create_updateMgr();
void add_element_updatable(updateManager* updateMgr, void* elem);
void update_elements(updateManager* updateMgr, float time_deltaTime);
void destroy_updateMgr(updateManager* updateMgr);

#endif