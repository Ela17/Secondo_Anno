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





/**
 * utilizzando la funzione:
*/
int max(int m, int n) {
  return m > n ? m : n;
}
// si definisca la funzione:

/**
 * pre: t!=NULL && t è un albero k-ario
 * post: ritorna il massimo delle somme delle etichette sui rami di t
*/
int maxSumBranch(kTree t) {
	if(t->child == NULL && t->sibling != NULL) return max(t->key, maxSumBranch(t->sibling));

	if(t->child != NULL && t->sibling != NULL)
		return max(t->key + maxSumBranch(t->child), maxSumBranch(t->sibling));

	if(t->child == NULL && t->sibling == NULL) return t->key;

	if(t->child != NULL && t->sibling == NULL) return t->key + maxSumBranch(t->child);

}
// suggerimento: si utilizzi una DFS modificata opportunamente

int main() {

// test 1
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
  printf("Massimo delle somme delle etichette sui rami: %d\n", maxSumBranch(t)); // stampa 48

}
