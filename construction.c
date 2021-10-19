#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "construction.h"


void printpokestat(struct pokestat *p) {

  printf("Pokemon: %s   \tBase Hp: %d\tBase Attack: %d\n", p->pokemon, p->basehp, p->baseattack);

}


struct pokestat * createpoke(char *c, int i, int a) {

  struct pokestat *p = malloc(sizeof(struct pokestat));
  strcpy(p->pokemon, c);
  p->basehp = i;
  p->baseattack = a;
  p->next = 0;

  return p;

}


void print_list(struct pokestat *p) {
  printf("Pokemon: %s   \t HP: %d\t Attack: %d\n", p->pokemon, p->basehp, p->baseattack);
  if (p->next != 0)
    print_list(p->next);

}

struct pokestat * insert_front(struct pokestat *p, char *c, int i, int a) {
  struct pokestat *n = malloc(sizeof(struct pokestat));
  strcpy(n->pokemon, c);
  n->basehp = i;
  n->baseattack = a;
  n->next = p;
  return n;
}

struct pokestat * free_list(struct pokestat *p) {
  if (p->next)
    free_list(p->next);
  free(p);
  return p;
}

struct pokestat * remove_node(struct pokestat *front, int data) {
  struct pokestat *f = front;
  // special case for first node
  if (front->basehp == data) {
    f = front->next;
    return f;
  }
  while (front->next) {
    if (front->next->basehp == data) {
      front->next = front->next->next;
      return f;
    }
    front = front->next;
  }
  return f;
}

