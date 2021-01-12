#ifndef COMPONENT_H
#define COMPONENT_H
#include "behaviour.h"
#include <stdlib.h>

typedef struct 
{
    behaviour* data;
    void(*update)(void* self, float delta_time);
}component;

component* newComponent();
#endif