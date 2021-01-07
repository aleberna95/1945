#include "list.h"
#include "common.h"
#include <stdlib.h>

list *new_list()
{
    list *_list = (list *)malloc(sizeof(list));
    _list->__head = NULL;
    _list->__tail = NULL;
    _list->count = 0;
    return _list;
}

void list_destroy(list *list)
{
    node *each = list->__head;
    while (each != NULL)
    {
        node *next = each->next;
        free(each);
        each = next;
    }
    free(list);
}
void *list_elem_at(list *_list, int index)
{
    if (index > _list->count || index <= 0)
        return NULL;
    node *nod = _list->__head;

    for (int i = 1; i < index; i++)
    {
        nod = nod->next;
    }
    return nod->data;
}

void list_add(list *_list, void *elem)
{
    node *_node = (node *)malloc(sizeof(node));
    _node->data = elem;
    _node->next = NULL;
    _node->previous = NULL;

    if (_list->__head == NULL)
    {
        _list->__head = _node;
        _list->__tail = _node;
    }
    else
    {
        _node->previous = _list->__tail;
        _list->__tail->next = _node;
        _list->__tail = _node;
    }
    _list->count++;
}