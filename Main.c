# Practica-7
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
  list *l;
  l = create_list();
  add_init(l, 3);
  add_init(l, 9);
  delete_list(l);
  return 0;
  }
