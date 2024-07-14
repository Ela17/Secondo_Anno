#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct heapFrame {
	int dim, hd;
	int* keys;
};

typedef struct heapFrame* Heap;

Heap newHeap(int n) {
  Heap h = malloc(sizeof(struct heapFrame));
  h->dim = n;
  h->hd = 0;
  h->keys = malloc(n*sizeof(int));
  return h;
}

//supponendo che le funzioni seguenti siano già state implementate:
int left(Heap h, int i) {
  return 2*i+1;
}
int right(Heap h, int i) {
  return 2*i+2;
}
int parent(Heap h, int i) {
  return (i-1)/2;
}

void errorOverflow(bool b) {
  if (!b) {
	printf("Overflow\n");
	exit(1);
  }
}

void showHeap(Heap h) {
  for(int i = 0; i < h->hd; i++) {
	printf("%d ", h->keys[i]);
  }
  printf("\n");
}

void swap(int A[], int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

/*****************************/

// si definisca la funzione:
// pre: h heap minimo correttamente riempito H->keys[0..H->dim-1] con 0 <= H->hd < H->dim
// post: inserisce la chiave k nell'heap h e lo mantiene un heap minimo e
// 		restituisce true se l'inserimento è avvenuto con successo, false altrimenti
bool insert(Heap h, int k) {
	if(h->hd >= h->dim) return false;

	int index = h->hd;
	h->hd++;
	h->keys[index] = k;
	int i = parent(h, index);

	while(k < h->keys[i] && i >= 0) {
		swap(h->keys, index, i);
		index = i;
		i = parent(h, i);
	}
	if(i < 0) return false;
	return true;
}


int main() {
  // test
  Heap h = newHeap(5);
  for(int i = 6; i > 0; i--) {
	errorOverflow(insert(h, i));
	  printf("Inserito %d\n", i);
  }

  showHeap(h);
}