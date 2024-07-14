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

/*************************************************************************************/

// si definisca rank()
// pre: l è lista di interi eventualmente vuota
// post: l è stata trasformata nella lista dei ranghi dei suoi elementi;
// 		il valore ritornato è il rango del primo elemento rispetto alla lista originaria
// 		0 se lista vuota
int rank(list l) {
	if(l == NULL) return 0;

	l->info += rank(l->next);

	return l->info;
}

// non deve allocare alcun elemento! Deve essere O(n)

int main() {
  	list l = Cons(3, Cons(1, Cons(2, Cons(4, NULL))));
	printf("Prima:\t");
	printlist(l); // 3 1 2 4
	printf("Dopo: \trango = %d\n\t", rank(l));
	printlist(l);
  return 0;
}
