#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/***************************************************************************************/

// si definisca la funzione subset():

// pre: l, m liste ordiate crescenti
// post: ritorna true se l rappresenta un sottoinsieme di m
bool subset(list l, list m) {
	if(l == NULL) return true;
	else if(m == NULL || m->info > l->info) return false;
	else if(l->info == m->info) {
		return true && subset(l->next, m->next);
	}
	else return subset(l, m->next);
}


void test(list l, list m) {
	printf("List l: ");
	printlist(l);
	printf("List m: ");
	printlist(m);
	if (subset(l, m)) {
		printf("List l is a subset of list m.\n");
	} else {
		printf("List l is not a subset of list m.\n");
	}
}



int main() {
	list l1 = Cons(2, Cons(5, Cons(8, NULL)));
	list m1 = Cons(0, Cons(2, Cons(4, Cons(5, Cons(7, Cons(8, NULL))))));

	test(l1, m1);

	printf("---\n");
	list l2 = Cons(2, Cons(5, Cons(8, Cons(9, NULL))));

	test(l2, m1);

	printf("---\n");
	list l3 = NULL;

	test(l3, m1);

	printf("---\n");
	list m4 = NULL;

	test(l3, m4);

	printf("---\n");

	test(m1, m4);
}
