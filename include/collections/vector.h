#ifndef VECTOR_H
#define VECTOR_H

#include "common.h"

typedef struct  {
    void** __items;
    unsigned int __count;
    unsigned int __capacity;
}vector;

vector* new_vector();
vector* new_with_cap_vector(uint capacity);
void destroy_vector(vector* vect);
void add_vector(vector* vect, void* item);
void foreach_vector(vector* vect, void (*action)(void* elem));
vector* resize_vector(vector* vect, uint capacity);

#endif /* VECTOR_H */