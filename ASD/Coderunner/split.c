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

/**************************************************************************************************/

// Si dia un'implementazione di costo O(n) della funzione split():
// post: modifica distruttivamente l in modo che l contenga circa la metà
// 			degli elementi della lista data, e ritorna il puntatore alla
// 			lista della seconda metà
list split(list l) {
	if(l == NULL || l->next == NULL) return NULL;

	list slow = l;
	list fast = l->next;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	list res = slow->next;
	slow->next = NULL;

	return res;
}

// pre:  l, m ordinate in senso non decrescente
// post: fonde distruttivamente l m in una lista ordinata
list merge(list l, list m) {
	if (l == NULL) return m;
	else if (m == NULL) return l;
	else if (l->info <= m->info) {
		l->next = merge(l->next, m);
		return l;
	}
	else {  // l->info > m->info
		m->next = merge(l, m->next);
		return m;
	}
}

// in modo tale che l'implementazione dell'algoritmo Mergesort seguente:
// post: ordina distruttivamente l in senso non decrescente
// e ritorna il puntatore alla lista ordinata
list Mergesort(list l) {
	if (l == NULL || l->next == NULL)
		return l;
	else {
		list m = split(l);
		l = Mergesort(l);
		m = Mergesort(m);
		return merge(l, m);
	}
}

int main() {
	list l1 = Cons(4, Cons(1, Cons(3, Cons(9, Cons(1, NULL)))));
	printf("Lista data: ");
	printlist(l1);
	l1 = Mergesort(l1);
	printf("Output di Mergesort: ");
	printlist(l1);
}