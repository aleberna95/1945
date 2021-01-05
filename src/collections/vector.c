#include "vector.h"
#include <stdio.h>

vector* new_with_cap_vector(uint capacity){
    vector* vect = (vector*)malloc(sizeof(vector));
    if(vect == NULL) return;
    vect->__count = 0;
    vect->__capacity = capacity;
    vect->__items = malloc(vect->__capacity * sizeof(void*));
    if(vect->__items == NULL) return NULL;
    return vect;
    }

vector* new_vector(){
    return new_with_cap_vector(10);
}

void destroy_vector(vector* vect){
    vect->__count= 0;
    free(vect->__items);
    free(vect);
}

vector* resize_vector(vector* vect, uint capacity){
    void* ptr = realloc(vect->__items, capacity * sizeof(void*));
    if(ptr == NULL) return NULL;
    vect->__items = ptr;
    vect->__capacity = capacity;
    return vect;
}

void add_vector(vector* vect, void* item){
    if(vect->__count == vect->__capacity){
        resize_vector(vect, vect->__capacity*2);
    }

    int curr_index = vect->__count;
    vect->__items[curr_index] = item;
    vect->__count ++;
}

void foreach_vector(vector* vect, void (*action)(void* elem)){
    for(size_t i = 0; i < vect->__count; i++){
        action(vect->__items[i]);
    }
}


