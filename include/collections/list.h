#ifndef LIST_H
#define LIST_H

struct list_node{
    void* data;
    struct list_node * next;
    struct list_node * previous;
};
typedef struct list_node node;

struct list{
    node* __head;
    node* __tail;
    int count;
};
typedef struct list list;

list* new_list();
void list_destroy(list* list);
void list_add(list* list, void* elem);
void* list_elem_at(list* list, int index);

#endif 