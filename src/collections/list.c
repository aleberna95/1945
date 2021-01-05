#include "list.h"
#include <stdlib.h>

list* new_list(){
    list* _list = (list*)malloc(sizeof(list));
    _list->__head= NULL;
    _list->__tail = NULL;
    return _list;
}

void list_destroy(list* list){
    node* each = list->__head;
    while (each!= NULL)
    {
        node* next = each->next;
        free(each);
        each = next;
    }
    free(list);
}

void list_add(list* _list, void* elem){
    node* _node = (node*)malloc(sizeof(node));
    _node->data = elem;
    _node->next = NULL;

    if(_list->__head == NULL){
        _list->__head = _node;
        _list->__tail = _node;
    } else { 
        _list->__tail->next = _node;
        _list->__tail = _node;
    }
}