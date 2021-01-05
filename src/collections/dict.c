#include "dict.h"
#include <stdlib.h>

uint djb33x_hash(void* key, uint keylen) {
    int hash = 5381;
    unsigned char* key_as_num = (unsigned char*)key;

    for(int i=0; i<keylen; i++) {
        hash = ((hash << 5) + hash) ^ key_as_num[i];
    }
    return hash;
} 

dict* aiv_dict_new(){
    dict* _dict = (dict*)malloc(sizeof(dict));
    _dict->__capacity = 1;
    _dict->hashfunc = djb33x_hash;
    _dict->__hasmap = calloc(_dict->__capacity, sizeof(void*));
    return _dict;
}

void dict_put(dict* _dict, void* key, uint keylen, void* val){
    uint hash = _dict->hashfunc(key, keylen);
    uint hash_index = hash % _dict->__capacity;
    if(!_dict->__hasmap[hash_index]){
        node* _node = malloc(sizeof(node));
        _node->key = malloc(sizeof(keylen));
        memcpy_s(_node->key, keylen, key, keylen);

        _node->keylen = keylen;
        _node->value = val;
        _node->next = NULL;

        _dict->__hasmap[hash_index] = _node;
    } else {
        node* _node = _dict->__hasmap[hash_index];
        node* last = NULL;

        while (_node)
        {
            last = _node;
            if(_node->keylen == keylen && !memcmp(_node->key, key, keylen)){
                _node->value = val;
                return;
            }
            _node = _node->next;
        }
        
        node* new_node = (node*)malloc(sizeof(node));
        new_node->key = malloc(sizeof(keylen));
        memcpy_s(new_node->key, keylen, key, keylen);
        new_node->keylen = keylen; 
        new_node->value = val;
        new_node->next = NULL;

        last->next = new_node;
    }
}