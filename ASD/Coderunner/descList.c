#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

struct BtreeNd {
	int             key;
	struct BtreeNd* left;
	struct BtreeNd* right;
};

typedef struct BtreeNd* btree;

btree ConsTree(int k, btree l, btree r) {
  btree rootnode = malloc(sizeof(struct BtreeNd));
  rootnode->key = k;
  rootnode->left = l;
  rootnode->right = r;
  return rootnode;
}

// Funzione per inserire un nuovo nodo nell'albero binario di ricerca
btree insert(int key, btree root) {
	if (root == NULL) {
		// Se l'albero è vuoto, il nuovo nodo diventa la radice
		return ConsTree(key, NULL, NULL);
	}

	if (key < root->key) {
		// Se la chiave è minore della chiave della radice, inserisci nel sottoalbero sinistro
		root->left = insert(key, root->left);
	} else if (key > root->key) {
		// Se la chiave è maggiore della chiave della radice, inserisci nel sottoalbero destro
		root->right = insert(key, root->right);
	}

	// Restituisce il puntatore alla radice (non cambia)
	return root;
}

// post: stampa indentata dell'albero bt in preordine sinistro, con margine
//       iniziale di n tab, senza visualizzare i puntatori a nil
void printtree(btree bt, int n) {
  if (bt != NULL) {
	for (int i = 0; i < n; i++)
	  printf("   ");
	printf("%d\n", bt->key);
	printtree(bt->left, n + 1);
	printtree(bt->right, n + 1);
  }
}

// post: stampa indentata dell'albero bt in preordine sinistro, con margine
//       iniziale di n tab, visualizzando i puntatori a nil
void printtree2(btree bt, int n) {
  for (int i = 0; i < n; i++)
	printf("   ");
  if (bt == NULL)
	printf("nil\n");
  else {
	printf("%d\n", bt->key);
	printtree2(bt->left, n + 1);
	printtree2(bt->right, n + 1);
  }
}

// Funzione per determinare se un nodo è una foglia
bool isLeaf(btree bt) {
	if (bt == NULL) {
		return false; // Un nodo nullo non è una foglia
	}
	if (bt->left == NULL && bt->right == NULL) {
		return true; // Un nodo senza figli è una foglia
	}
	return false; // Altrimenti, non è una foglia
}


struct listEl {
	int            info;
	struct listEl* next;
};

typedef struct listEl *list;

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

/***********************************************************************************************/
list DescList_aux(btree bt, list l);
list DescList(btree bt);

// si definisca la funzione:
// pre: bt albero binario di ricerca
// post: ritorna la lista ordinata decrescente contenente le chiavi di bt
list DescList(btree bt) {
	if(bt == NULL) return NULL;
	return DescList_aux(bt, NULL);
}

// si utilizzi una funzione ausiliaria:
// che ritorna la lista delle chiavi di bt in ordine decrescente davanti a l
list DescList_aux(btree bt, list l) {
	if(bt == NULL) return l;

	if(isLeaf(bt)) return Cons(bt->key, l);
	else {
		l = DescList_aux(bt->left, l);
		return DescList_aux(bt->right, Cons(bt->key,l));
	}
}



int main() {
	// Costruiamo un albero binario di ricerca
	btree bt = insert(45, NULL);
	bt = insert(23, bt);
	bt = insert(52, bt);
	bt = insert(12, bt);
	bt = insert(48, bt);
	bt = insert(1, bt);
	bt = insert(7, bt);

  printf("Albero binario di ricerca:\n");
	printtree(bt, 0);

  // Otteniamo e stampiamo la lista delle chiavi in ordine decrescente
  list descendingList = DescList(bt);
  printf("\nLista delle chiavi in ordine decrescente:\n");
  printlist(descendingList);

  return 0;
}