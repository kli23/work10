#include "construction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  //creating first node
  struct pokestat *a = createpoke("Charizard", 289, 222);
  print_list(a);
  printf("\n");
  //testing insert_front and print_list
  a = insert_front(a, "Zekrom", 251, 331);
  print_list(a);
  printf("\n");
  a = insert_front(a, "Bulbasaur", 454, 120);
  print_list(a);
  printf("\n");
  a = remove_node(a, 251); // remove middle node
  print_list(a);
  printf("\n");
  a = remove_node(a, 100); // int not in list, no removal
  print_list(a);
  printf("\n");
  a = remove_node(a, 289); // last node test case
  print_list(a);
  printf("\n");
  a = insert_front(a, "Zekrom", 251, 331);
  print_list(a);
  printf("\n");
  a = remove_node(a, 251); // first node test case
  print_list(a);
  printf("\n");

  a = free_list(a);
  print_list(a);
  return 0;
}