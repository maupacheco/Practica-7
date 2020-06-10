# Practica-7
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

list *create_list(){
    list *l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->num = 0;
    return l;
}

bool remove_list(list *l){
    if(!is_empty_list(l))
        empty_list(l);
    free(l);
    return true;
}

DATA search_list(list *l, int pos){
    if(pos == 0) return l->head->data;
    else if(pos == l->num-1) return l->tail->data;
    else if(pos >0 && pos < l->num-2){
        node *t = l->head->next;
        for(int i=1; i<l->num-2; i++){
            if(i==pos) return i;
            t = t->next;
        }
    }
    return -1;
}

node* search_node_list(list *l, int pos){
    if(pos == 0) return l->head;
    else if(pos == l->num-1) return l->tail;
    else if(pos >0 && pos < l->num-2){
        node *t = l->head->next;
        for(int i=1; i<l->num-1; i++){
            if(i==pos) return t;
            t = t->next;
        }
    }
    return NULL;
}

int locate_list(list *l, DATA data){
    node *t = l->head;
    for(int i= 0; i <l->num; i++){
        if(t->data==data) return i;
        t = t->next;
    }
    return -1;
}

void print_list(list *l){
    node *t = l->head;
    printf("[ ");
    for(int i=0; i < l->num-1; i++){
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("%d ", t->data);
    printf("]\n");
}

void empty_list(list *l){
    if(is_empty_list(l)) return;
    node *t = l->head;
    while(remove_init(l));
}

bool delete_data(list *l, DATA data){
    dnode *t = l->head;
    for(int i =0; i < l->num; i++){
        if(t->data == data){
            if(t == l->head) return remove_init(l);
        }
    }
}

bool is_empty_list(list *l){
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}

bool insert_init(list* l, DATA data){
    if(l == NULL) return false;
    node *nuevo = create_node(data);
    if(is_empty_list(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        nuevo->next = nuevo;
        l->num =1;
        return true;
    }
    nuevo->next = l->head;
    l->tail->next = nuevo;
    l->head = nuevo;
    l->num++;
    return true;
}

bool insert_end(list* l, DATA data){
    if(l == NULL) return false;
    node *nuevo = create_node(data);
    if(is_empty_list(l)){        
        l->head = nuevo;
        l->head->next = nuevo;
        l->tail = nuevo;
        l->num =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->next = l->head;
    l->tail = nuevo;
    l->num++;
    return true;
}

bool insert_list(list* l, DATA data,  int pos){
    if(l == NULL) return false;
    node *nuevo = create_node(data);
    if(pos ==0) return insert_init(l, data);
    else if(pos == l->num)
        return insert_end(l,data);
    else if(pos >0 && pos< l->num-1){
        node *t = l->head->next;
        for(int i =1; i < pos; i++){
            t= t->next;
        }
        nuevo->next = t;        
        l->num++;
        return true;
    }
    return false;
}

bool remove_end(list *l){
    if(l == NULL || is_empty_list(l)) return false;
    if(l->head ==l->tail){
        l->head ->next = NULL;
        remove_node(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    node *t = l->head->next
    t->next =   NULL;
    l->tail->next = NULL;
    t->next = l->head;
    remove_node(l->tail);
    l->tail = t;
    l->num--;
    return true;
}

bool remove_init(list *l){
    if(l == NULL || is_empty_list(l)) return false;
    if(l->head ==l->tail){
        l->head ->next = NULL;
        remove_node(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    node *t = l->head->next;
    l->head->next= NULL;
    remove_node(l->head);
    l->tail->next = t;
    l->head = t;
    l->num--;
    return true;
}

bool remove_pos(list *l ,int pos){
    if(pos == 0){
        return remove_init(l);
    }else if(pos == l->num-1){
        return remove_end(l);
    }else if(pos>0 && pos < l->num-2){
        node *t = l->head->next;
        for(int i =1; i < pos; i++){
            t= t->next;
        }
        node *next = t->next;        
        t->next = NULL;
        remove_node(t);
        l->num--;
        return true;
    }
    return false;
}


