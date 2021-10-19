
struct pokestat {
  char pokemon[40];
  int basehp;
  int baseattack;
  struct pokestat *next;

};

void printpokestat(struct pokestat *p);

struct pokestat * createpoke(char *c, int i, int a);

void print_list(struct pokestat *p);

struct pokestat * insert_front(struct pokestat *p, char *c, int i, int a);

struct pokestat * free_list(struct pokestat *p);

struct pokestat * remove_node(struct pokestat *front, int data);