#include <stdio.h>
#include <stdlib.h>

struct kTreeVertex {
	int                  key;
	struct kTreeVertex*  child;
	struct kTreeVertex*  sibling;
};

typedef struct kTreeVertex* kTree;

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


/**************************************************************************/

// si definisca la funzione:
// pre: dg, ht >= 0 e se ht > 0 allora dg > 0
// post: genera l'albero completo di grado dg e altezza ht, con etichette tutte uguali a key
kTree complete(int key, int dg, int ht) {
	if(ht < 0) return NULL;
	kTree root = consTree(key, NULL, NULL);

	if(ht > 0) {
		kTree curr = NULL;
		for(int i = 0; i < dg; i++) {
			kTree new = complete(key, dg, ht-1);
			if(curr == NULL)
				root->child = new;
			else curr->sibling = new;

			curr = new;
		}
	}

	return root;
}


int main() {
  int key = 1;   // Etichetta delle chiavi
  int dg = 3;    // Grado dell'albero completo
  int ht = 3;    // Altezza dell'albero completo

  printf("Creazione di un albero completo di grado %d e altezza %d con etichetta %d:\n", dg, ht, key);
  kTree completeTree = complete(key, dg, ht);
  printTree(completeTree, 0);

  return 0;
}
