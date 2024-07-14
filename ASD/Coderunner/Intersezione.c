#include <stdio.h>
#include <stdlib.h>

struct listEl {
	int            info;
	struct listEl* next;
};

typedef struct listEl* list;

list Cons(int x, list xs) {
  list newlist = malloc(sizeof(struct listEl));
  newlist->info = x;
  newlist->next = xs;
  return newlist;
}

void printlist (list l) {
  while (l != NULL) {
	printf("%d ", l->info);
	l = l->next;
  }
  printf("\n");
}

/********************************************************************************************/

// si definisca la funzione:
// pre: l, m liste ordinate crescenti
// post: ritorna la lista ordinata crescente contenente gli elementi in comune di l e m
list intersect(list l, list m) {
	if(l == NULL || m == NULL) return NULL;

	if(m->info == l->info) {
		return Cons(m->info, intersect(l->next, m->next));
	}
	else if(m->info < l->info) {
		return intersect(l, m->next);
	}
	else {
		return intersect(l->next, m);
	}
}


int main() {
  // Creazione di due liste ordinate crescenti
  list l = Cons(2, Cons(5, Cons(7, NULL)));
  list m = Cons(5, Cons(6, Cons(7, Cons(8, NULL))));

  printf("Lista l: ");
  printlist(l);

  printf("Lista m: ");
  printlist(m);

  // Calcolo dell'intersezione tra l e m
  list intersection = intersect(l, m);

  printf("Intersezione: ");
  printlist(intersection);

  return 0;
}