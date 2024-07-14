#include <stdio.h>
#include <stdlib.h>

struct listEl {
	int            info;
	struct listEl* next;
};

typedef struct listEl *list;

list Cons(int x, list xs);
void printlist(list xs);
list concat(list xs, list ys);

struct kTreeVertex {
	int                  key;
	struct kTreeVertex*  child;
	struct kTreeVertex*  sibling;
};

typedef struct kTreeVertex* kTree;

kTree consTree(int k, kTree c, kTree s);
kTree leaf(int k, kTree s) ;

kTree root(int k, kTree c);
void printTree(kTree t, int d);

list Cons(int x, list xs) {
  list newlist = malloc(sizeof(struct listEl));
  newlist->info = x;
  newlist->next = xs;
  return newlist;
}

void printlist(list xs) {
  while (xs != NULL) {
	printf("%d ", xs->info);
	xs = xs->next;
  }
  printf("\n");
}

list concat(list xs, list ys) {
  if (xs == NULL)
	return ys;
  else
	return Cons(xs->info, concat(xs->next, ys));
}

kTree consTree(int k, kTree c, kTree s) {
  kTree t = malloc(sizeof(struct kTreeVertex));
  t->key = k;
  t->child = c;
  t->sibling = s;
  return t;
}

kTree leaf(int k, kTree s) {
  return consTree(k, NULL, s);
}

kTree root(int k, kTree c) {
  return consTree(k, c, NULL);
}

// post: stampa indentata dell'albero t con margine
//       iniziale di n tab
void printTree(kTree t, int d) {
  if (t != NULL)
	for (int i = 0; i < d; ++i)
	  printf("   ");
  printf("%d\n", t->key);
  kTree cl = t->child;
  while (cl != NULL) {
	printTree(cl, d + 1);
	cl = cl->sibling;
  }
}



/**********************************************************************************************************/

// dato un albero di arietà arbitraria (albero k-ario)
// il brodo è l'insieme delle foglie dell'albero
// usando l'implementazione degli alberi k-ari con etichette intere
// e quella delle liste di interi:

// è possibile usare la funzione concat()


// si definisca la funzione fringe():
// pre: t!=NULL && t è un albero k-ario
// post: ritorna la lista delle foglie dell'albero t da sinistra verso destra
list fringe(kTree t) {
	if(t == NULL) return NULL;
	if(t->child == NULL) {
		return concat(Cons(t->key, NULL), fringe(t->sibling));
	}
	return concat(fringe(t->child), fringe(t->sibling));
}


int main() {
  kTree t =
		  root(12,
			   consTree(22,
						leaf(1,NULL),
						leaf(2,
							 root(32,
								  leaf(3,
									   leaf(4, NULL)
								  )
							 )
						)
			   )
		  );



/* t in forma indentata:
12
	22
		1
	2
	32
		3
		4
*/

  printf("Albero dato:\n");
  printTree(t, 0);

  printf("\nLista etichette foglie:\n");
  list fr = fringe(t);
  printlist(fr);

}