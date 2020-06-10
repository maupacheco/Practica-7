# Practica-7
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

dnode *create_node(DATA data){
    node *d = (node*)malloc(sizeof(node));
    d->next = NULL;
    d->data = data;
    return d;
}

bool remove_node(node *n){
    if(n->next == NULL){
        free(n);
        return true;
    }
    return false;
}
