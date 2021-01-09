#include "dict.h"
#include <stdlib.h>

uint djb33x_hash(void *key, uint keylen)
{
    int hash = 5381;
    unsigned char *key_as_num = (unsigned char *)key;

    for (int i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key_as_num[i];
    }
    return hash;
}

dict *new_dict()
{
    dict *_dict = (dict *)malloc(sizeof(dict));
    _dict->__capacity = 1;
    _dict->hashfunc = djb33x_hash;
    _dict->__hasmap = calloc(_dict->__capacity, sizeof(void *));
    return _dict;
}

void *dict_elem_at_key(dict *_dict, void *key, uint keylen)
{
    dict_node *node = _dict->__hasmap[0];
    uint _hash_dict_key = _dict->hashfunc(node->key, node->keylen);
    uint _hashkey = _dict->hashfunc(key, keylen);
    if (_hash_dict_key == _hashkey)
        return node->value;
    node = node->next;
    for (size_t i = 0; i < _dict->__capacity; i++)
    {
        _hash_dict_key = _dict->hashfunc(node->key, node->keylen);
        if (_hash_dict_key == _hashkey)
            return node->value;

        node = node->next;
    }
    return NULL;
}

void dict_put(dict *_dict, void *key, uint keylen, void *val)
{
    uint hash = _dict->hashfunc(key, keylen);
    uint hash_index = hash % _dict->__capacity;
    if (!_dict->__hasmap[hash_index])
    {
        dict_node *_node = malloc(sizeof(dict_node));
        _node->key = malloc(sizeof(keylen));
        memcpy_s(_node->key, keylen, key, keylen);

        _node->keylen = keylen;
        _node->value = val;
        _node->next = NULL;

        _dict->__hasmap[hash_index] = _node;
    }
    else
    {
        dict_node *_node = _dict->__hasmap[hash_index];
        dict_node *last = NULL;

        while (_node)
        {
            last = _node;
            if (_node->keylen == keylen && !memcmp(_node->key, key, keylen))
            {
                _node->value = val;
                return;
            }
            _node = _node->next;
        }

        dict_node *new_node = (dict_node *)malloc(sizeof(dict_node));
        new_node->key = malloc(sizeof(keylen));
        memcpy_s(new_node->key, keylen, key, keylen);
        new_node->keylen = keylen;
        new_node->value = val;
        new_node->next = NULL;

        last->next = new_node;
    }
}