#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct _list list;

struct _list{
    node *head;
    node *tail;
    int num;
};

list *create_list();
bool remove_list(list *l);

bool insert_init(list *l, DATA data);
bool insert_end(list *l, DATA data);
bool insert_list(list *l, DATA data, int pos);

bool remove_init(list *l);
bool remove_end(list *l);
bool remove_pos(list *l ,int pos);

DATA search_list(list *l, int pos);
int locate_list(list *l, DATA data);

void print_dlist(list *l);

bool is_empty_list(list *l);
void empty_list(list *l);

bool delete_data(list *l, DATA data);
#endif
