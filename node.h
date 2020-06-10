# Practica-7
#ifndef NODE_H
#define NODE_H
#include <stdbool.h>

typedef struct _node node;
typedef int DATA;

struct _node{
    DATA data;
    node *next;
};

node *create_node(DATA data);
bool remove_node(node *n);
#endif
