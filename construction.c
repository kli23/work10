#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct pokestat {
  char pokemon[40];
  int basehp;
  int baseattack;
  struct pokestat *next;

  };

void print_list(struct pokestat *p) {
  if (p->next != 0)
    print_list(p->next);
  printf("Pokemon: %s   \t HP: %d\t Attack: %d\n", p->pokemon, p->basehp, p->baseattack);
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
  if (p->next != 0)
    free_list(p->next);
  p->next = 0;
  return p;
}

int main() {
  //creating first node
  struct pokestat *a = malloc(sizeof(struct pokestat));
  char *ch = "Pikachu";
  strcpy(a->pokemon,ch);
  a->basehp = 124;
  a->baseattack = 231;

  //testing insert_front and print_list
  struct pokestat *b = insert_front(a, "Zekrom", 251, 331);
  struct pokestat *c = insert_front(b, "Bulbasaur", 454, 120);
  print_list(a);
  printf("\n");
  print_list(b);
  printf("\n");
  print_list(c);

  free_list(c);
  print_list(c);

}
/*
void printpokestat(struct pokestat *p) {

  printf("Pokemon: %s   \tBase Hp: %d\tBase Attack: %d\n", p->pokemon, p->basehp, p->baseattack);

}


struct pokestat * structheap(char *c, int i, int a) {

  struct pokestat *p = malloc(sizeof(struct pokestat));
  strcpy(p->pokemon, c);
  p->basehp = i;
  p->baseattack = a;

  return p;

}


int main() {
  //setting up random numbers
  srand( time(NULL) );

  int x = rand() % 1000;
  int y = rand() % 1000;
  struct pokestat *a = structheap("Pikachu", x,y);
  printpokestat(a);

  x = rand() % 1000;
  y = rand() % 1000;
  a = structheap("Zekrom", x,y);
  printpokestat(a);

  x = rand() % 1000;
  y = rand() % 1000;
  struct pokestat *b = structheap("Snivy", x,y);
  printpokestat(b);

  return 0;
}
*/
