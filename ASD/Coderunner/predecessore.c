#include <stdio.h>
#include <stdlib.h>

struct BtreeNd {
	int             key;
	struct BtreeNd* parent;
	struct BtreeNd* left;
	struct BtreeNd* right;
};

typedef struct BtreeNd* btree;

// pre: k etichetta, p punta al padre (NULL se si alloca la radice)
//      l punta al figlio sinistro, r al figlio destro (NULL se assenti)
// post: alloca un nuovo nodo con etichetta k, padre p,
//       figlio sin. l e figlio des. r
btree ConsTree(int k, btree p, btree l, btree r) {
	btree rootnode = malloc(sizeof(struct BtreeNd));
	rootnode->key = k;
	rootnode->parent = p;
	rootnode->left = l;
	rootnode->right = r;
	return rootnode;
}

// post: stampa indentata dell'albero bt con margine
//       iniziale di n tab
void printtree(btree bt, int n) {
	if (bt != NULL) {
		for (int i = 0; i < n; i++)
			printf("   ");
		printf("%d\n", bt->key);
		printtree(bt->left, n + 1);
		printtree(bt->right, n + 1);
	}
}

btree insert(int key, btree root, btree parent) {
	if (root == NULL) {
		return ConsTree(key, parent, NULL, NULL);
	}
	if (key < root->key) {
		root->left = insert(key, root->left, root);
	} else if (key > root->key) {
		root->right = insert(key, root->right, root);
	}
	return root;
}

int max(int m, int n) {
	return m > n ? m : n;
}


/******************************************************************/

// Si implmentino le seguenti funzioni:

// pre: bt != NULL è un albero binario di ricerca
// post: ritorna il puntatore al nodo con chiave massima in bt
btree maxInBtree(btree bt);
// pre: nd != NULL è un nodo di un albero binario di ricerca
// post: ritorna l'avo sinistro più prossimo a nd se esiste; NULL altrimenti
btree leftAncestor(btree nd);
// pre: nd != NULL punta ad un nodo di un albero binario di ricerca
// post: ritorna il puntatore al predecessore di nd se esiste
// NULL altrimenti
btree predecessor(btree nd);

/*
dove in un albero di ricerca si definisce avo sinistro di un nodo nd un nodo il cui sottoalbero destro contenga nd
(quindi è un avo di nd e si trova a "sinistra" di nd); si definisce predecessore di nd un nodo la cui chiave sia massima
tra tutte quelle minori di nd->key.
Suggerimento: la funzione predecessor() utilizza le funzioni maxInBtree() e leftAncestor()
 */

btree maxInBtree(btree bt) {
	if(bt->right == NULL) return bt;

	return maxInBtree(bt->right);
}

btree leftAncestor(btree nd) {
	if(nd->parent == NULL) return NULL;
	else if(nd == nd->parent->right) return nd->parent;
	else return leftAncestor(nd->parent);
}

btree predecessor(btree nd) {
	if(nd->left != NULL) return maxInBtree(nd->left);
	else return leftAncestor(nd);
}



void predTest2(int key, btree root) {
	btree current = root;
	while (current != NULL && current->key != key) {
		if (key < current->key) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	if (current == NULL) {
		printf("Nodo con chiave %d non trovato.\n", key);
		return;
	}
	btree pred = predecessor(current);
	if (pred != NULL) {
		printf("Il predecessore del nodo con chiave %d è %d.\n", key, pred->key);
	} else {
		printf("Il nodo con chiave %d non ha predecessore.\n", key);
	}
}

int main() {
	btree bt1 = insert(45, NULL, NULL);
	bt1 = insert(23, bt1, NULL);
	bt1 = insert(52, bt1, NULL);
	bt1 = insert(12, bt1, NULL);
	bt1 = insert(48, bt1, NULL);
	bt1 = insert(1, bt1, NULL);
	bt1 = insert(7, bt1, NULL);
	printf("Albero dato:\n");
	printtree(bt1, 0);
	predTest2(52, bt1);
	predTest2(48, bt1);
	predTest2(1, bt1);
}