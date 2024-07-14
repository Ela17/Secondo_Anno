#include <stdio.h>
#include <stdlib.h>

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

int left(Heap h, int i) {
	if((2*i+1) <= h->hd)
  		return 2*i+1;
	else return i;
}
int right(Heap h, int i) {
	if((2*i+2) <= h->hd)
		return 2*i+2;
	else return i;
}
int parent(Heap h, int i) {
	if((i-1)/2 >= 0)
  		return (i-1)/2;
	else return -1;
}

void printHeap(Heap H) {
  printf("Heap: ");
  for (int i = 0; i < H->hd; ++i) {
	printf("%d ", H->keys[i]);
  }
  printf("\n");
}

void swap(int A[], int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

// si definisca la funzione DecreaseKey():
// pre: H è uno heap minimo correttamente allocatoe newKey < H->keys[i]
// post: il vecchio valore di H->keys[i]  è stato sostituito con newKey (ad esso minore) e
//       H->keys[0...H->hd-1] è stato ristrutturato in modo da essere nuovamente uno heap minimo
void DecreaseKey(Heap H, int i, int newKey) {
	H->keys[i] = newKey;
	int j = i;

	while(j > 0) {
		if(newKey < H->keys[parent(H, j)]) swap(H->keys, j, parent(H,j));
		j = parent(H,j);
	}
}
// che sostituisce la chiave in posizione i con newKey ad esso minore e ristruttura l'array in modo da mantenere la proprietà di heap minimo.


int main() {
  // Creiamo un nuovo heap con capacità iniziale 10
  Heap H = newHeap(10);

  // Inseriamo alcune chiavi nell'heap
  H->keys[H->hd++] = 3;
  H->keys[H->hd++] = 5;
  H->keys[H->hd++] = 4;
  H->keys[H->hd++] = 10;
  H->keys[H->hd++] = 8;

  printf("Heap dopo l'inserimento iniziale:\n");
  printHeap(H);

  // Eseguiamo DecreaseKey per diminuire la chiave in posizione 3 da 10 a 2
  int index = 3;
  int newKey = 2;
  printf("\nEseguo DecreaseKey(%d, %d)\n", index, newKey);
  DecreaseKey(H, index, newKey);

  printf("Heap dopo DecreaseKey:\n");
  printHeap(H);

  // Eseguiamo DecreaseKey per diminuire la chiave in posizione 0 da 2 a 1
  index = 0;
  newKey = 1;
  printf("\nEseguo DecreaseKey(%d, %d)\n", index, newKey);
  DecreaseKey(H, index, newKey);

  printf("Heap dopo DecreaseKey:\n");
  printHeap(H);


  // Deallochiamo la memoria dell'heap
  free(H->keys);
  free(H);

  return 0;
}