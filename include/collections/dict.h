#ifndef DICT_H
#define DICT_H

#include "common.h"
#include <string.h>

typedef struct dict_node node;
struct dict_node{
    void* key;
    uint keylen;
    void* value;
    node* next;
};

typedef struct {
    node** __hasmap;
    uint __capacity;
    uint (*hashfunc)(void*, uint keylen);
}  dict;

dict* new_dict();
void put_dict();

#endif