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

list copyList(list l) {
  if (l == NULL)
	return NULL;
  return Cons(l->info, copyList(l->next));
}

// si definisca la funzione unione():
// pre: l, m liste ordinate crescenti
// post: ritorna la lista ordinata crescente contenente gli elementi non comuni di l e m
list unione(list l, list m){
	if(l == NULL) return copyList(m);
	if(m == NULL) return copyList(l);

	if(l->info < m->info) {
		return Cons(l->info, unione(l->next,m));
	}
	if(l->info > m->info) {
		return Cons(m->info, unione(l, m->next));
	}
	else {
		return Cons(m->info, unione(l->next, m->next));
	}
}
// unione() non deve essere distruttiva, si utilizzi copyList() che copia una lista in un'altra lista


int main() {
  // Creazione di due liste ordinate crescenti
  list l = Cons(2, Cons(5, Cons(7, NULL)));
  list m = Cons(5, Cons(6, Cons(7, Cons(8, NULL))));

  printf("Lista l: ");
  printlist(l);

  printf("Lista m: ");
  printlist(m);

  // Calcolo dell'unione tra l e m
  list unionList = unione(l, m);

  printf("Unione: ");
  printlist(unionList);

  return 0;
}