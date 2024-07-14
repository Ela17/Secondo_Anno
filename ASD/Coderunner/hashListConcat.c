#include <stdlib.h>
#include <stdio.h>

// Liste doppie di trabocco

struct listEl {
	int            info;
	struct listEl* pred; // puntatore al predecessore
	struct listEl* next; // puntatore al successivo
};

typedef struct listEl* list;

// post: inserisce la chiave x in un frame
//       il cui predecessore è p e successore è n
list Cons(int x, list p, list n) {
  list newlist = malloc(sizeof(struct listEl));
  newlist->info = x;
  newlist->pred = p;
  newlist->next = n;
  return newlist;
}

void printlist (list l) {
  while (l != NULL) {
	printf("%d ", l->info);
	l = l->next;
  }
  printf("\n");
}

// Tabelle hash con concatenzaione

struct hashFrame {
	int       dim;  // dimensione della tabella
	list*   array;  // puntatore alla tabella array[0..dim-1]
};

typedef struct hashFrame* HashTable;

// pre:  0 < m
// post: ritorna una tabella hash di dimensione m a chiavi intere;
//       la tabella contiene m puntatori a liste di trabocco ed è
//       inizializzata con tutti NULL
HashTable newHashTable(int m)
{
  HashTable T = malloc(sizeof(struct hashFrame));
  T->dim = m;
  T->array = malloc(m * sizeof(list));
  for(int i = 0; i < m; i++)
	T->array[i] = NULL;
  return T;
}

// pre:  0 <= k chiave, 0 < m == dimensione della tabella
// post: ritorna k mod m
int hashFun(int k, int m)
{
  return k % m;
}

void showTable (HashTable T) {
  for (int i = 0; i < T->dim; i++) {
	printf("%d : ", i);
	printlist(T->array[i]);
  }
}

/*
 * si definiscano le funzioni ordIndert() e hashInsert():
*/

// post: inserimento ordinato crescente (senza ripetizioni) della chiave k davanti alla lista l con predecessore p
list ordInsert(int k, list l, list p) {
	if(l == NULL) return Cons(k, p, NULL);

	list current = l;
	while(current != NULL && current->info < k) {	// trova la posizione corretta
		p = current;
		current = current->next;
	}

	if(current != NULL && current->info == k) // chiave già presente
		return l;

	if(p == NULL) {	// INSERIMENTO IN TESTA
		return Cons(k, NULL, l);
	}
	else {
		p->next = Cons(k, p, current);
		return l;
	}
}

// post: inserisce la chiave k in T se assente
void hashInsert(int k, HashTable T) {
	int index = hashFun(k, T->dim);
	T->array[index] = ordInsert(k, T->array[index], NULL);
}

// usando ordInsert() nella definizione di hashInsert, ossia producendo liste di trabocco in senso crescente, dunque senza ripetizioni di chiavi


int main () {
  HashTable T = newHashTable(5);
  int A[] = {7, 15, 34, 12, 35, 27, 5, 12, 16};
  int dimA = sizeof(A) / sizeof(int);

  //test hashInsert
  for (int i = 0; i < dimA; i++) {
	hashInsert(A[i], T);
  }
	printf("Stato della tabella:\n");
	showTable(T);
  return 0;
}