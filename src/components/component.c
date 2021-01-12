#include "component.h"

component* newComponent() {
    component* comp = (component*)malloc(sizeof(component));

    comp->data = (behaviour*)malloc(sizeof(behaviour));
    return comp;
}