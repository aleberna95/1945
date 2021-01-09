#ifndef DICT_H
#define DICT_H

#include "common.h"
#include <string.h>

typedef struct dict_node dict_node;
struct dict_node{
    void* key;
    uint keylen;
    void* value;
    dict_node* next;
};

typedef struct {
    dict_node** __hasmap;
    uint __capacity;
    uint (*hashfunc)(void*, uint keylen);
}  dict;

dict* new_dict();
void put_dict(dict *_dict, void *key, uint keylen, void *val);
void* dict_elem_at_key(dict* _dict, void* key, uint keylen);

#endif